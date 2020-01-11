package business;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Calendar;

import bean.Debtor;
import bean.Person;
import bean.Product;
import repositories.Repository;

public class SystemFacade {
	
	private static SystemFacade instance = null;
	private BusinessDebtor businessDebtor;
	
	
	private SystemFacade() {
		this.businessDebtor = new BusinessDebtor();
		
		try {
			
			Repository<Debtor> debtors = this.businessDebtor.getRepositoryDebtor();
			debtors.loadFromFile(new FileInputStream("data/Debtors.bin"));
		
		} catch( IOException | ClassNotFoundException exception ) {
			exception.printStackTrace();
		}
		
		int update = systemAmountUpdate();
		for( int k = 0; k < update; k++ )
			this.debtorUpdateSystem();
		
		System.out.println("System updates: " + update);
	}
	
	/*
	 * Read last date and check last update date and return the amount of needed updates
	 */
	public static int systemAmountUpdate() {
		
		ObjectInputStream loader;
		Calendar today = Calendar.getInstance();
		Calendar lastAccess = null;
		
		try {
			
			System.out.println(System.getProperty("user.dir"));
			
			FileInputStream file = new FileInputStream("data/Date.bin");
			loader = new ObjectInputStream(file);
			lastAccess = (Calendar) loader.readObject();
			loader.close();
			
		} catch(IOException | ClassNotFoundException exception) {
			System.out.println("Problem to load: Date.bin");
			//exception.printStackTrace();
			return 0;
		}
		
		// Date of system is less than last update (error)
		if( today.compareTo(lastAccess) < 1 ) {
			System.out.println("Check the actual system's date");
			return 0;
		}
			
		// Normally difference is greater than zero
		int differenceYear = today.get(Calendar.YEAR) - lastAccess.get(Calendar.YEAR);
		
		return today.get(Calendar.MONTH) - lastAccess.get(Calendar.MONTH) + (12 * differenceYear);
	}
	
	
	public static SystemFacade getInstance() {
		if( instance == null ) {
			instance = new SystemFacade();
		}
		
		return instance;
	}
	
	
	public void shutdownSystem() {
		
		try {
			
			Repository<Debtor> debtors = this.businessDebtor.getRepositoryDebtor();
			debtors.saveOnFile(new FileOutputStream("data/Debtors.bin"));
			
			// Save date's access
			FileOutputStream file = new FileOutputStream("data/Date.bin");
			ObjectOutputStream saver = new ObjectOutputStream(file);
			
			saver.writeObject(Calendar.getInstance());
			
			saver.flush();
			saver.close();
		
		} catch( IOException exception ) {
			System.out.println("Error to save: Debtors.bin | Date.bin");
			exception.printStackTrace();
		}
	}
	
	
	public Repository<Debtor> debtorsGetRepositoryDebtor() {
		return this.businessDebtor.getRepositoryDebtor();
	}
	
	
	public ArrayList<Debtor> debtorsGetDebtors() {
		return this.businessDebtor.getDebtors();
	}
	
	
	public Debtor debtorNewAcquisition(String personName, String productName, double price, int installmentsAmount) throws Exception {
		return this.businessDebtor.newAcquisition(personName, productName, price, installmentsAmount);
	}
	
	
	public int debtorGetAvailableId() {
		return this.businessDebtor.getAvailableId();
	}
	
	
	public double debtorTotalDebtSystemPerMonth() {
		return this.businessDebtor.totalDebtSystemPerMonth();
	}
	
	
	public boolean debtorUpdateDebtor(Debtor update, Person newPerson) throws Exception {
		return this.businessDebtor.updateDebtor(update, newPerson);
	}
	
	public boolean debtorUpdateDebtor(Debtor update, Product oldProduct, Product newProduct) throws Exception {
		return this.businessDebtor.updateDebtor(update, oldProduct, newProduct);
	}
	
	
	public Debtor debtorSearchForPerson(Person seeked) {
		return this.businessDebtor.searchForPerson(seeked);
	}
	
	
	public boolean debtorDeleteDebtorFromPerson(Person seeked) {
		return this.businessDebtor.deleteDebtorFromPerson(seeked);
	}
	
	
	public int debtorIndexOfDebtor(Person seeked) {
		return this.businessDebtor.indexOfDebtor(seeked);
	}
	
	
	public Debtor debtorAssociation(Person person, Product product) {
		return this.businessDebtor.association(person, product);
	}
	public Debtor debtorAssociation(Person person, ArrayList<Product> product) {
		return this.businessDebtor.association(person, product);
	}
	
	
	public double debtorTotalDebtOf(Debtor debtor) {
		return this.businessDebtor.totalDebtOf(debtor);
	}
	
	
	public boolean debtorRemoveProduct(Debtor debtor, String productName) {
		return this.businessDebtor.removeProduct(debtor, productName);
	}
	
	
	public void debtorUpdateSystem() {
		this.businessDebtor.updateSystem();
	}
	

}
