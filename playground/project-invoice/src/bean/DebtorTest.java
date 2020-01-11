package bean;

import java.util.ArrayList;
import java.util.Calendar;

public class DebtorTest {
	
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
		
		ArrayList<Product> products = new ArrayList<Product>();
		products.add(p1);
		products.add(p2);
		
		Person joao = new Person("Joao");
		
		Debtor debtor = new Debtor(joao, products);
		
		System.out.println("Name of debtor: " + debtor.getName());
		System.out.println("Products of debtor: \n" + debtor.getProducts().toString());
		
	}

}
