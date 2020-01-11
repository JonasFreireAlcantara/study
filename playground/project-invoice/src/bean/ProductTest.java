package bean;

import java.util.Calendar;

public class ProductTest {

	public static void main (String[] args) {
		Product p1 = new Product(	"Cama box",
									788.34,
									Calendar.getInstance(),
									10,
									1,
									98
				);
		
		Product p2 = new Product(	"Cama box",
									788.34,
									Calendar.getInstance(),
									10,
									1,
									98
				);
		
		System.out.println("Is p1 equals to p2 ? " + p1.equals(p2));
		
		System.out.println("Name of p1: " + p1.getName());
		System.out.println("Price of p1: " + p1.getPrice());
		System.out.println("Date of p1: " + p1.getDate());
		System.out.println("Installments amount of p1: " + p1.getInstallmentsAmount());
		System.out.println("Actual installment of p1: " + p1.getActualInstallment());
		System.out.println("Id of p1: " + p1.getId());
	}
	
}
