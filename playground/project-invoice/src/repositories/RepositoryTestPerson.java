package repositories;

import bean.Person;

public class RepositoryTestPerson {
	
	public static void main(String[] args) {
		Repository<Person> persons = new Repository<Person>();
		
		Person p1 = new Person("Joao");
		Person p2 = new Person("Jeca Tatu");
//		Person p3 = new Person("Joana");
		
		persons.add(p1);
		System.out.println("Size of persons = " + persons.size());
		
		System.out.println("===============================================");
		
		persons.add(p2);
		System.out.println("Size of persons = " + persons.size());
		
		System.out.println("===============================================");
		
		int index = persons.search(p1);
		System.out.println("index = " + index);
		
		System.out.println("===============================================");
		
		System.out.println("Is p1 equals to persons.get(0) ? " + persons.get(0).equals(p1));
		
		System.out.println("===============================================");
		
		persons.remove(0);
		System.out.println("Size of persons = " + persons.size());
		
	}
	
}
