package business;

import repositories.Repository;
import bean.Debtor;
import bean.Person;
import bean.Product;

import java.util.ArrayList;
import java.util.Calendar;

public class BusinessDebtor {
	
	
	private Repository<Debtor> debtors;
	
	
	public BusinessDebtor() {
		this.debtors = new Repository<Debtor>();
	}
	
	public BusinessDebtor(ArrayList<Debtor> debtors) {
		this.debtors = new Repository<Debtor>(debtors);
	}
	
	
	public Repository<Debtor> getRepositoryDebtor() {
		return this.debtors;
	}
	
	
	public ArrayList<Debtor> getDebtors() {
		return this.debtors.getElements();
	}
	
	
	/*
	 * Return the summation of all debts
	 */
	public double totalDebtSystemPerMonth() {
		double sum = 0;
		for( int k = 0; k < this.debtors.size(); k++ )
			sum = sum + this.debtors.get(k).getTotalOfDebtPerMonth();
		
		return sum;
	}
	
	
	/*
	 * Perform a new Acquisition of element by a person
	 * 	basically the acquisition of new product
	 */
	public Debtor newAcquisition( String personName, String productName, double price, int installmentsAmount ) throws Exception {
		if( personName == null || productName == null || installmentsAmount < 0 ) 
			throw new Exception("Problema na programação newAcquisition method");
		
		int disponibleId = this.getAvailableId();
		Calendar date = Calendar.getInstance();
		int actualInstallment = 1;
		
		Person person = new Person(personName);
		Product product = new Product(productName, price, date, installmentsAmount, actualInstallment, disponibleId);
		
		return this.association(person, product);
	}

	
	/*
	 * Search for all products on repository of debtors
	 * 	and your respectively products, and return a available id
	 */
	public int getAvailableId() {
		ArrayList<Product> products = new ArrayList<Product>();
		
		for ( int k = 0; k < this.debtors.size(); k++ ) { // Add all products on variable products
			products.addAll(this.debtors.get(k).getProducts());
		}
		
		int id = 0;
		while (true) {
			
			boolean alreadyExists = false;
			
			for ( int k = 0; k < products.size(); k++ ) { // Now search for an available id
				if( products.get(k).getId() == id ) {
					alreadyExists = true;
					break;
				}
			}
			
			if( alreadyExists ) 
				id++;
			else
				break;
		
		}
		
		return id;
	}
	
	
	/*
	 * Update a debtor with a new person
	 */
	public boolean updateDebtor(Debtor update, Person newPerson) throws Exception {
		if( update == null || newPerson == null )
			throw new Exception("Problema na programaçao");
		
		Debtor verify = this.searchForPerson(update.getPerson());
		
		if( verify == null  ) // Invalid Debtor
			return false;
		
		verify.setPerson(newPerson);
		return true;
	}
	
	/*
	 * Update a product of a debtor
	 */
	public boolean updateDebtor(Debtor update, Product oldProduct, Product newProduct) throws Exception {
		if( update == null || oldProduct == null || newProduct == null )
			throw new Exception("Problema na programação");
		
		Debtor verify = this.searchForPerson(update.getPerson());
		
		if( verify == null  ) // Invalid Debtor
			throw new Exception("Devedor não encontrado");
		
		// Verification of settings
		if(newProduct.getPrice() < 0)
			throw new Exception("Preço da parcela não pode ser negativo");
		
		if(newProduct.getActualInstallment() < 1)
			throw new Exception("Parcela atual deve ser maior ou igual a 1");
		
		if(newProduct.getInstallmentsAmount() <= 0)
			throw new Exception("Quantidade de parcelas não pode ser negativo");
		
		if(newProduct.getActualInstallment() > newProduct.getInstallmentsAmount())
			throw new Exception("Parcela atual é maior que a quantidade de parcelas");
		
		// Continuation of update
		ArrayList<Product> products = verify.getProducts();
		for( int k = 0; k < products.size(); k++ ) { // Search for the old product to update
			if( products.get(k).equals(oldProduct) ) {
				products.set(k, newProduct);
				return true;
			}
		}
		
		return false;
	}
	
	
	/*
	 * Search debtor from person associated
	 */
	public Debtor searchForPerson(Person seeked) {
		if( seeked == null ) 
			return null;
		
		for( int k = 0; k < this.debtors.size(); k++ ) {
			Person compare = this.debtors.get(k).getPerson();
			if( compare.equals(seeked) ) 
				return this.debtors.get(k);
		}
		
		return null;
	}
	
	
	/*
	 * Delete debtor from person
	 */
	public boolean deleteDebtorFromPerson(Person seeked) {
		int index = this.indexOfDebtor(seeked);
		
		if( index == -1 )
			return false;
		
		this.debtors.remove(index);
		return true;
	}
	
	
	/*
	 * Index of debtor from person
	 */
	public int indexOfDebtor(Person seeked) {
		if( seeked == null ) 
			return -1;
		
		for( int k = 0; k < this.debtors.size(); k++ ) {
			Person compare = this.debtors.get(k).getPerson();
			if( compare.equals(seeked) ) 
				return k;
		}
		
		return -1;
	}
	
	
	/*
	 * Associate a person and a product with a debtor,
	 * 	create a new debtor or update an existent debtor
	 */
	public Debtor association(Person person, Product product) {
		if( person == null || product == null ) 
			return null;
		
		Debtor existent = this.searchForPerson(person);
		
		if( existent == null ) { // Create a new Debtor instance
			ArrayList<Product> products = new ArrayList<Product>(); // Creating array list of products
			products.add(product);									// On this case just one element
			
			Debtor newDebtor = new Debtor(person, products);
			
			this.debtors.add(newDebtor);
			
			return newDebtor;
		} else { // Update old debtor instance with a new product acquisition
			existent.getProducts().add(product);
			
			return existent;
		}
			
	}
	
	public Debtor association(Person person, ArrayList<Product> product) {
		if( person == null || product == null ) 
			return null;
		
		Debtor existent = this.searchForPerson(person);
		
		if( existent == null ) { // Create a new Debtor instance
			ArrayList<Product> products = new ArrayList<Product>(); // Creating array list of products
			products.addAll(product);								// On this case just one element
			
			Debtor newDebtor = new Debtor(person, products);
			
			this.debtors.add(newDebtor);
			
			return newDebtor;
		} else { // Update old debtor instance with a new product acquisition
			existent.getProducts().addAll(product);
			
			return existent;
		}
			
	}
	

	/*
	 * Return the total value of debt from a debtor
	 */
	public double totalDebtOf(Debtor debtor) {
		ArrayList<Product> products = debtor.getProducts();
		
		double total = 0;
		for( int k = 0; k < products.size(); k++ )
			total = total + products.get(k).getPrice();
		
		return total;
	}
	
	
	/*
	 * Remove product of debtor from product name
	 */
	public boolean removeProduct(Debtor debtor, String productName ) {
		if( debtor == null || productName == null ) 
			return false;
		
		if( this.searchForPerson(debtor.getPerson()) == null )
			return false;
		
		ArrayList<Product> products = debtor.getProducts();
		
		for( int k = 0; k < products.size(); k++ ) {
			if( products.get(k).getName().equals(productName) ) {
				products.remove(k);
				if(debtor.getProducts().size() == 0)
					this.deleteDebtorFromPerson(debtor.getPerson());
				return true;
			}
		}
		
		
		return false;
	}
	
	
	/*
	 * Increment the actual installment of all debtor
	 */
	public void updateSystem() {
		for( int k = 0; k < this.debtors.size(); k++ ) {
			Debtor debtor = this.debtors.get(k);
			ArrayList<Product> products = debtor.getProducts(); // Get the products of a debtor
			for( int j = 0; j < products.size(); j++ ) {
				Product product = products.get(j);
				int nextInstallment = product.getActualInstallment() + 1;
				if( nextInstallment == product.getInstallmentsAmount() ) { // Remove the product
					this.removeProduct(debtor, product.getName());
					break;
				}
				product.setActualInstallment(nextInstallment);
			}
		}
	}
	
	
	
}
