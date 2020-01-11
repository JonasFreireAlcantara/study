/*
 * This files constains functions of the system
 * 
 * @author: Jonas Freire
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SIZE_READ_SEND 10

#define RECEIVE_FILE_OPTION		1
#define SEND_FILE_OPTION		2
#define SELECT_FILE_LOCATION_OPTION	3
#define SELECT_IP_PAIR_OPTION		4
#define SELECT_PORT_PAIR_OPTION		5
#define QUIT				6

#define FILE_LOCATION_BUFFER_SIZE	1024
#define IP_PAIR_BUFFER_SIZE		16


/*
 * This function gets data from file and sends through
 * the socket specified, and returns the number of data bytes sent
 * 
 * @ socket_fd	->	socket descriptor where the data will sent
 * @ file_fd	->	file descriptor where is found the data source
 * @ byte_total	->	amount of bytes which will be sent to the socket
 */
int read_and_send (int socket_fd, FILE* file_fd, int byte_total) {
	
	int number_byte_read;
	int number_byte_sent;
	int total_data_sent = 0;
	int tries;
	
	// Allocate space to buffer
	char *data = malloc (1);
	
	// Main loop
	while (byte_total > 0) {
		// Read data from file to buffer
		number_byte_read = fread (data, 1, 1, file_fd);
		if (number_byte_read != 1) {
			perror ("file read");
			exit (EXIT_FAILURE);
		}
		
		// Send data through socket
		// Retry while the data wasn't sent or the number of attempts
		// do not exceed 10
		number_byte_sent = 0;
		tries = 0;
		while (tries < 10) {
			
			number_byte_sent = send (socket_fd, data, 
						 number_byte_read, 0);
			
			if (number_byte_sent == 1) {
				total_data_sent += 1;
				break;
			} else if (number_byte_sent == -1) {
				perror ("net send data");
				exit (EXIT_FAILURE);
			} else {
				tries += 1;
			}
			
		}
		
		// Decrement the total number of data remaining
		byte_total -= 1;
	}
	
	// Deallocate space of buffer
	free (data);
	
	// Return the number of total bytes sent
	return total_data_sent;
}


/*
 * This function gets data from socket and stores to the file specified
 * and returns the number of data bytes stored
 * 
 * @ socket_fd	->	socket descriptor where the data will be received
 * @ file_fd	->	file descriptor where is the data destiny
 * @ byte_total	->	amount of bytes which will be sent to the file
 */
int receive_and_store (int socket_fd, FILE* file_fd, int byte_total) {
	
	int number_byte_received;
	int number_byte_stored;
	int total_data_stored = 0;
	
	// Print start transfer information
	printf ("Start to receive file\n");
	
	// Allocate space to buffer
	char *data = malloc (1);
	
	// Main loop
	while (byte_total > 0) {
		// Read data from socket to buffer
		number_byte_received = recv (socket_fd, data, 1, 0);
		if (number_byte_received == -1) {
			perror ("net data arrived");
			exit (EXIT_FAILURE);
		}
		
		// Store data to file
		number_byte_stored = fwrite (data, 1, 1, file_fd);
		if (number_byte_stored != 1) {
			perror ("file write");
			exit (EXIT_FAILURE);
		}
		total_data_stored += 1;
		
		// Decrement the total number of data remaining
		byte_total -= 1;
	}
	
	// Print end transfer information
	printf ("File received\n");
    getchar ();
	
	// Deallocate space of buffer
	free (data);
	
	// Return the number of total bytes stored
	return total_data_stored;
}


/*
 * This function prints the optional menu and returns an integer
 * which determine the choiced option
 * 
 * @ Return options:
 * @ 1	->	receive file
 * @ 2	->	send file
 * @ 3	->	select the file location
 * @ 4	->	select the IP pair
 * @ 5	->	select the port pair
 * @ 6	->	quit
 * 
 * @ file_location	->	null terminated string containing the file
 * 				location
 * @ pair_ip		->	null terminated string containing 
 * 				the ip pair address
 * @ port		->	port's pair number
 */
int menu (char* file_location, char* ip_pair, int port) {
	
	while (1) {
		printf ("\tCOPY SYSTEM\n");
		printf ("----------------------------------------------\n");
		
		printf ("1	->	Receive file\n");
		printf ("2	->	Send file\n");
		printf ("3	->	Select the file location\n");
		printf ("4	->	Select the IP pair\n");
		printf ("5	->	Select the port pair\n");
		printf ("6	->	quit\n");
		printf ("----------------------------------------------\n");
		printf ("File location %s\n", file_location);
		printf ("IP pair       %s\n", ip_pair);
		printf ("Port pair     %d\n", port);
		printf ("----------------------------------------------\n");
		printf (">>> ");
		
		int choice;
		
		scanf ("%d", &choice);
		scanf ("%[^\n]"); getchar ();
		
		if (choice > 6 || choice < 1) {
			printf ("Invalid entry try again\n");
			getchar ();
			continue;
		}
		
		return choice;
	}
}


/*
 * This function prompts the user to enter the file location
 * and updates the file_location variable
 * 
 * @ file_location	->	null terminated string containing the actual
 * 				file location
 * @ buffer_length	->	integer containing the buffer size
 */
void select_file_location (char* file_location, int buffer_length) {
	
	printf ("\tFILE LOCATION\n");
	printf ("----------------------------------------------\n");
	printf ("Actual file location: %s\n", file_location);
	printf ("----------------------------------------------\n");
	printf ("Enter new name\n>>> ");
	
	scanf ("%1024[^\n]", file_location);
	scanf ("%[^\n]s"); getchar ();
}


/*
 * This function prompts the user to enter the IP pair
 * and updates the ip_pair variable
 * 
 * @ ip_pair		->	null terminated string containing the actual
 * 				ip pair
 * @ buffer_length	->	integer containing the buffer size
 */
void select_ip_pair (char* ip_pair, int buffer_length) {
	
	printf ("\tIP PAIR\n");
	printf ("----------------------------------------------\n");
	printf ("Actual IP pair: %s\n", ip_pair);
	printf ("----------------------------------------------\n");
	printf ("Enter new IP pair\n>>> ");
	
	scanf ("%16[^\n]", ip_pair);
	scanf ("%[^\n]"); getchar ();
}


/*
 * This function prompts the user to enter the port pair
 * and updates the port variable
 * 
 * @ port		->	pointer to the actual port pair
 */
void select_port_pair (int *port) {
	
	printf ("\tPORT PAIR\n");
	printf ("----------------------------------------------\n");
	printf ("Actual port pair: %d\n", *port);
	printf ("----------------------------------------------\n");
	printf ("Enter new port pair\n>>> ");
	
	scanf ("%d", port);
	scanf ("%[^\n]"); getchar ();
}


/*
 * In this system the receiver process will act as a client while the
 * sender process as a server.
 * 
 * When the send file option was up, the sender process becomes into
 * mode server and waits for the requisition.
 * When the receive file options was up, the sender process becomes into
 * mode client sending the requisition.
 * 
 * Note:
 * If the receive file was set before the receive file was corrected
 * set the transfer don't occur. 
 */


/*
 * This function creates a new server socket and returns the socket descriptor
 * 
 * @ port	->	Host byte order port number
 */
int make_server_socket (int port) {
	
	int socket_fd = socket (PF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0) {
		perror ("socket");
		exit (EXIT_FAILURE);
	}
	
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons (port);
	address.sin_addr.s_addr = INADDR_ANY;
	
	if (bind (socket_fd, (struct sockaddr *) &address, 
		sizeof (struct sockaddr)) == -1) {
		perror ("bind");
		exit (EXIT_FAILURE);
	}
	
	return socket_fd;
}


/*
 * DO NOT USE THIS
 * 
 * This function creates a new client socket and returns the socket descriptor
 * 
 * @ ip_pair	->	null terminated string containing the ip pair address
 * @ port	->	Host byte order port number pair
 */
int make_client_socket (char* ip_pair, int port) {
	
	int socket_fd = socket (PF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0) {
		perror ("socket");
		exit (EXIT_FAILURE);
	}
	
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons (port);
	address.sin_addr.s_addr = INADDR_ANY;
	
	if (bind (socket_fd, (struct sockaddr *) &address, 
		sizeof (struct sockaddr)) == -1) {
		perror ("bind");
		exit (EXIT_FAILURE);
	}
	
	return socket_fd;
}


/*
 * This function executes the send of file
 * 
 * @ file_location	->	null terminated string containing the file
 * 				location
 * @ port		->	local port number
 */
void send_file (char* file_location, int port) {
	
	if (file_location == NULL) {
		printf ("Invalid file location\n");
		getchar ();
		return;
	}
	
	// Open file on read mode
	FILE *file_fd = fopen (file_location, "rb");
	if (file_fd < 0) {
		perror ("file read");
		exit (EXIT_FAILURE);
	}
	
	// Discover the size of file
	fseek (file_fd, 0, SEEK_END);
	int total_file_size = ftell (file_fd);
	fseek (file_fd, 0, SEEK_SET);
	
	// Create and set local port to server socket
	int server_socket_fd = make_server_socket (port);
	
	// Enable socket to listen
	if (listen (server_socket_fd, 1) < 0) {
		perror ("listen");
		exit (EXIT_FAILURE);
	}
	
	// Accept requisition from client process
	struct sockaddr_in pair_address;
	int pair_address_size = sizeof (struct sockaddr_in);
	int connect_socket_fd = accept (server_socket_fd, 
				     (struct sockaddr *) &pair_address,
				     &pair_address_size	);
	if (connect_socket_fd < 0) {
		perror ("accept");
		exit (EXIT_FAILURE);
	}
	
	// Print start transfer information
	printf ("Ready to send file\n");
	printf ("You can set the receiver proccess now\n");

	// Send the total file size
	if (send (connect_socket_fd, &total_file_size, sizeof (int), 0) < 0) {
		perror ("send total file size");
		exit (EXIT_FAILURE);
	}
	
	// Begin the transfer
	read_and_send (connect_socket_fd, file_fd, total_file_size);
    
    // Print end transfer information
	printf ("File sent\n");
	getchar ();
	
	// Close file
	fclose (file_fd);
	
	// Close server socket and connect socket
	close (connect_socket_fd);
	close (server_socket_fd);
}


/*
 * This function executes the receive of file
 * 
 * @ file_location	->	null terminated string containing the file
 * 				location
 * @ ip_pair		->	null terminated string containing the
 * 				IP's pair address
 * @ port		->	port's pair number
 */
void receive_file (char* file_location, char* ip_pair, int port) {
	
	if (file_location == NULL) {
		printf ("Invalid file location\n");
		getchar ();
		return;
	}
	
	if (ip_pair == NULL) {
		printf ("Invalid IP pair\n");
		getchar ();
		return;
	}
	
	// Open file on write mode
	FILE *file_fd = fopen (file_location, "wb");
	if (file_fd < 0) {
		perror ("file write");
		exit (EXIT_FAILURE);
	}
	
	// Create client socket
	int client_socket_fd = socket (PF_INET, SOCK_STREAM, 0);
	if (client_socket_fd < 0) {
		perror ("socket");
		exit (EXIT_FAILURE);
	}
	
	// Connect client socket to the server
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons (port);
	inet_aton (ip_pair, &server_address.sin_addr);
	if (connect (client_socket_fd, (struct sockaddr *) &server_address,
		sizeof (struct sockaddr)) < 0) {
		perror ("connect");
		exit (EXIT_FAILURE);
	}
	
	// Discover the size of file
	int total_file_size;
	if (recv (client_socket_fd, &total_file_size, sizeof (int), 0) < 0) {
		perror ("receive total file size");
		exit (EXIT_FAILURE);
	}
	
	// Begin the transfer
	receive_and_store (client_socket_fd, file_fd, total_file_size);
	
	// Close file
	fclose (file_fd);
	
	// Close client socket
	close (client_socket_fd);
}


int main () {
	
	int option;
	char file_location[FILE_LOCATION_BUFFER_SIZE];
	char ip_pair[IP_PAIR_BUFFER_SIZE];
	int port;
	
	file_location[0] = '\0';
	ip_pair[0] = '\0';
	port = 0;
	
	do {
		option = menu (file_location, ip_pair, port);
		
		switch (option) {
			case SELECT_FILE_LOCATION_OPTION:
				printf ("file_location = %p\n", file_location);
				select_file_location (file_location, 
					FILE_LOCATION_BUFFER_SIZE);
				printf ("file_location = %p\n", file_location);
				break;
			
			case SELECT_IP_PAIR_OPTION:
				select_ip_pair (ip_pair, IP_PAIR_BUFFER_SIZE);
				break;
			
			case SELECT_PORT_PAIR_OPTION:
				select_port_pair (&port);
				break;
			
			case SEND_FILE_OPTION:
				send_file (file_location, port);
				break;
			
			case RECEIVE_FILE_OPTION:
				receive_file (file_location, ip_pair, port);
				break;
			
			default:
				// Do nothing
				break;
		}
	} while (option != 6);
	

	exit (EXIT_SUCCESS);
}

