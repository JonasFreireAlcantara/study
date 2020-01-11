package textsystem;

import java.util.Scanner;

import bean.Debtor;
import bean.Person;
import bean.Product;
import business.SystemFacade;



public class TextSystem {
	
	static SystemFacade system = SystemFacade.getInstance();
	
	static Scanner input = new Scanner(System.in);
	
	public static int menu() {
		System.out.println("Options:");
		System.out.println("1 - Create");
		System.out.println("2 - Recovery");
		System.out.println("3 - Edit");
		System.out.println("4 - Delete");
		System.out.println("5 - Update");
		System.out.println("9 - Exit");
		
		System.out.print(">>> ");
		return Integer.parseInt(input.nextLine());
	}
	
	
	public static void createMenu() throws Exception {
		System.out.println("Create:\n");
		System.out.print("Type the name of the product: ");
		String productName = input.nextLine();
		System.out.print("Type the price of the product: ");
		double productPrice = Double.parseDouble(input.nextLine());
		System.out.print("Type the amount of product's installments: ");
		int productInstallmentsAmount = Integer.parseInt(input.nextLine());
		System.out.println("========================");
		System.out.print("Type the name of the person: ");
		String personName = input.nextLine();
		
		Debtor newDebtor = system.debtorNewAcquisition(personName, productName, productPrice, productInstallmentsAmount);
		
		if( newDebtor != null )
			System.out.println("Creation sucessfull !!!");
		else
			System.out.println("Creation error");
	}
	
	
	public static void recoveryMenu() {
		System.out.println("Recovery:\n");
		System.out.print("Type the name of the debtor: ");
		String name = input.nextLine();
		
		Debtor debtor = system.debtorSearchForPerson(new Person(name));
		
		if( debtor == null ) {
			System.out.println("Debtor not found");
			return;
		}
		
		System.out.println("Informations about " + debtor.getPerson().getName() + ":\n");
		System.out.println("Total products number: " + debtor.getProducts().size());
		for( int k = 0; k < debtor.getProducts().size(); k++ ) {
			System.out.println("--------------------------");
			System.out.println(debtor.getProducts().get(k).toString());
		}
		System.out.println();
		System.out.println("Total debt of " + debtor.getPerson().getName() + ": " + system.debtorTotalDebtOf(debtor));
	}
	
	
	public static void editMenu() {
		System.out.println("Edit:\n");
		
		System.out.print("Type the name of the debtor: ");
		String name = input.nextLine();
		Person person = new Person(name);
		
		Debtor debtor = system.debtorSearchForPerson(person);
		
		if( debtor == null ) {
			System.out.println("Debtor not found");
			return;
		}
		
		System.out.println("What you want to update:\n");
		System.out.println("1 - Name of debtor");
		System.out.println("2 - Name of product");
		System.out.println("3 - Price of product");
		System.out.println("4 - Installments amount");
		System.out.println("5 - Actual installment");
		System.out.println();
		System.out.print(">>> ");
		int option = Integer.parseInt(input.nextLine());
		switch( option ) {
			case 1: { // Debtor's name
				System.out.print("Type the new name of debtor: ");
				name = input.nextLine();
				debtor.getPerson().setName(name);
				
				break;
			}
			case 2: { // Product's name
				System.out.print("Type the name of the product desired: ");
				name = input.nextLine();
				
				Product product = debtor.search(name);
				if( product == null ) {
					System.out.println("Product not found");
					break;
				}
				
				System.out.print("Type the new name of product: ");
				name = input.nextLine();
				product.setName(name);
				
				break;
			}
			case 3: { // Product's price
				System.out.print("Type the name of the product desired: ");
				name = input.nextLine();
				
				Product product = debtor.search(name);
				if( product == null ) {
					System.out.println("Product not found");
					break;
				}
				
				System.out.print("Type the new price of product: ");
				double price = Double.parseDouble(input.nextLine());
				product.setPrice(price);
				
				break;
			}
			case 4: { // Product's installments amount
				System.out.print("Type the name of the product desired: ");
				name = input.nextLine();
				
				Product product = debtor.search(name);
				if( product == null ) {
					System.out.println("Product not found");
					break;
				}
				
				System.out.print("Type the new installments amount of product: ");
				int installmentsAmount = Integer.parseInt(input.nextLine());
				product.setInstallmentsAmount(installmentsAmount);
				
				break;
			}
			case 5: { // Product's actual installment
				System.out.print("Type the name of the product desired: ");
				name = input.nextLine();
				
				Product product = debtor.search(name);
				if( product == null ) {
					System.out.println("Product not found");
					break;
				}
				
				System.out.print("Type the new actual installment of product: ");
				int actualInstallment = Integer.parseInt(input.nextLine());
				product.setActualInstallment(actualInstallment);
				
				break;
			}
			default: { // Incorrect option
				System.out.println("Incorrect option");
				break;
			}
		}
		
		
		
	}
	
	
	public static void deleteMenu() {
		System.out.println("Delete:\n");
		
		System.out.print("Type the name of the debtor: ");
		String name = input.nextLine();
		Person person = new Person(name);
		
		Debtor debtor = system.debtorSearchForPerson(person);
		
		if( debtor == null ) {
			System.out.println("Debtor not found");
			return;
		}
		
		System.out.println("What you want to delete:\n");
		System.out.println("1 - Debtor");
		System.out.println("2 - One product");
		System.out.println();
		System.out.print(">>> ");
		int option = Integer.parseInt(input.nextLine());
		switch( option ) {
			case 1: { // Debtor delete
				System.out.println("Are you sure to delete debtor: " + debtor.getPerson().getName() + " ? (y - 1 / n - 0)\n");
				option = Integer.parseInt(input.nextLine());
				if( option == 1 ) {
					boolean deleteSucessfull = system.debtorDeleteDebtorFromPerson(debtor.getPerson());
					
					if( deleteSucessfull )
						System.out.println("Delete sucessfull !!!");
					else
						System.out.println("Delete unsucessfull");
				}
				
				break;
			}
			case 2: { // Product delete
					System.out.print("Type the name of the product desired: ");
					name = input.nextLine();
					
					boolean deleteSucessfull = system.debtorRemoveProduct(debtor, name);
					
					if( deleteSucessfull )
						System.out.println("Delete sucessfull !!!");
					else
						System.out.println("Delete unsucessfull");

					
					break;
			}
			default: { // Incorrect option
				System.out.println("Incorrect option");
				break;
			}
		}
	}
	
	
	public static void update() {
		system.debtorUpdateSystem();
	}
	
	
	public static void main(String[] args) throws Exception {
		int option = menu();
		
		while( option != 9 ) {
			switch( option ) {
				case 1: { // Create
					createMenu();
					break;
				}
				case 2: {
					recoveryMenu();
					break;
				}
				case 3: {
					editMenu();
					break;
				}
				case 4: {
					deleteMenu();
					break;
				}
				case 5: {
					update();
					break;
				}
				default: {
					System.out.println("Incorrect option !!!");
					System.out.println("Try Again\n\n");
					break;
				}
			}
			
			option = menu();
		}
		
		System.out.println("\n\nShutdown system\n\n");
	}
	
}
