#include <stdio.h>
#include <string.h>


#define HEIGHT 28
#define WIDTH 28
#define BITS_PER_PIXEL 8
#define FILE_SIZE HEIGHT*WIDTH
#define DIB_HEADER_SIZE 40
#define COLORS_USED 256


struct bmp_header {
	uint8_t signature[2];
	uint32_t file_size;
	uint32_t reserved;
	uint32_t data_offset;
};

struct info_header {
	uint32_t size;
	uint32_t width;	// Horizontal width of bitmap in pixels
	uint32_t height;// Vertical width of bitmap in pixels
	uint16_t planes;
	uint16_t bits_per_pixel;
	uint32_t compression;
	uint32_t image_size;
	uint32_t x_pixels_per_m;
	uint32_t y_pixels_per_m;
	uint32_t colors_used;
	uint32_t important_colors;
};

int main() {
	
	struct bmp_header* bmp_hdr = 
		(struct bmp_header*) malloc(sizeof(bmp_header));
		
	struct info_header* info_hdr = 
		(struct info_header*) malloc(sizeof(info_header));
		
	FILE* out_file = fopen('image.bmp', 'wb');
	FILE* in_file = fopen('train-images-idx3-ubyte', 'rb');
	
	// Fill memory with zeros
	memset(bmp_hdr, 0, sizeof(struct bmp_header));
	memset(info_hdr, 0, sizeof(struct info_header));
	
	strcpy(bmp_hdr->signature, "BM");
	bmp_hdr->file_size = FILE_SIZE
	bmp_hdr->data_offset = sizeof(struct bmp_header) + sizeof(struct info_header);
	
	info_hdr->size = DIB_HEADER_SIZE;
	info_hdr->width = WIDTH;
	info_hdr->height = HEIGHT;
	info_hdr->bits_per_pixel = BITS_PER_PIXEL;
	info_hdr->colors_used = COLORS_USED;
	
	// TODO read pixel data from file
	
	// TODO setup pixel data
		
	// TODO write data to file
	
	// TODO close files
	
	// TODO free allocated memories
	
	return 0;
}
