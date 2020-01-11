package bean;

import java.io.Serializable;
import java.util.ArrayList;

public class Debtor implements Serializable {
	
	private Person person;
	private ArrayList<Product> products;
	
	public Debtor(Person person) {
		this.person = person;
		this.products = new ArrayList<Product>();
	}
	
	public Debtor(Person person, ArrayList<Product> products) {
		this.person = person;
		this.products = products;
	}

	
	public double getTotalOfDebt() {
		double sum = 0;
		
		for( int k = 0; k < this.products.size(); k++ )
			// Compute the total of debt per product
			sum = sum + (this.products.get(k).getPrice() * this.products.get(k).getInstallmentsAmount());
		
		return sum;
	}
	
	
	public double getTotalOfDebtPerMonth() {
		double sum = 0;
		
		for( int k = 0; k < this.products.size(); k++ )
			sum = sum + this.products.get(k).getPrice();
		
		return sum;
	}

	public int getAmountOfProducts() {
		return this.products.size();
	}

	public String getName() {
		return this.person.getName();
	}

	
	public void setPerson(Person person) {
		this.person = person;
	}
	
	public Person getPerson() {
		return this.person;
	}
	
	
	public ArrayList<Product> getProducts() {
		return products;
	}

	public void setProducts(ArrayList<Product> products) {
		this.products = products;
	}

	
	/*
	 * Return an instance of product from a name of him
	 */
	public Product search( String name ) {
		for( int k = 0; k < this.products.size(); k++ ) {
			if(this.products.get(k).getName().equals(name))
				return this.products.get(k);
		}
		
		return null;
	}
	
	
	public boolean equals(Debtor compare) {
		if( !(this.person.equals(compare.person)) ) 
			return false;
		
		if ( !(this.products.equals(compare.getProducts())) )
			return false;
		
		return true;
	}
	
}
