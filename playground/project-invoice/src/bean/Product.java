package bean;

import java.io.Serializable;
import java.util.Calendar;

public class Product implements Serializable {
	
	private String name;
	private double price;	// Total of product not installments price
	private Calendar date;
	private int installmentsAmount;
	private int actualInstallment;
	private int id;
	
	
	public Product(String name) {
		this.name = name;
	}
	
	public Product (String name, double price, Calendar date, int installmentsAmount, int actualInstallment, int id) {
		this.name = name;
		this.price = price;
		this.date = date;
		this.installmentsAmount = installmentsAmount;
		this.actualInstallment = actualInstallment;
		this.id = id;
	}

	
	
	public double getTotalPrice() {
		return this.price * this.installmentsAmount;
	}
	
	

	public Calendar getDate() {
		return date;
	}


	public String getName() {
		return name;
	}


	public double getPrice() {
		return price;
	}


	public int getInstallmentsAmount() {
		return installmentsAmount;
	}


	public int getActualInstallment() {
		return actualInstallment;
	}
	
	
	public int getId () {
		return this.id;
	}


	public void setName(String name) {
		this.name = name;
	}


	public void setPrice(double price) {
		this.price = price;
	}


	public void setDate(Calendar date) {
		this.date = date;
	}
	
	
	public void setInstallmentsAmount(int installmentsAmount) {
		this.installmentsAmount = installmentsAmount;
	}


	public void setActualInstallment(int actualInstallment) {
		this.actualInstallment = actualInstallment;
	}
	
	
	public void setId (int id) {
		this.id = id;
	}
	
	
	public boolean equals (Product compare) {
		if (!compare.name.equals(compare.name))
			return false;
		
		if (this.price != compare.price)
			return false;
		
		if (this.actualInstallment != compare.actualInstallment)
			return false;
		
		if (this.installmentsAmount != compare.installmentsAmount)
			return false;
		
		if (this.id != compare.id)
			return false;
		
		return true;
	}

	
	public String toString() {
		return new String(	"name - " + this.name + 
							" price - " + this.price +
							" date - " + this.date.getCalendarType() +
							" installments amont - " + this.installmentsAmount +
							" actual installments - " + this.actualInstallment +
							" id - " + this.id
						 );
	}
}
