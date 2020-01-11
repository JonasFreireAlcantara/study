package bean;

public class PersonTest {

	public static void main(String[] args) {
		Person p1 = new Person("Joao");
		Person p2 = new Person("Joana");
		Person p3 = new Person("Joao");
		
		System.out.println("Is p1 equals at p2 ? " + p1.equals(p2));
		System.out.println("Is p1 equals at p3 ? " + p1.equals(p3));
		System.out.println("Is p2 equals at p3 ? " + p2.equals(p3));
		
		System.out.println("Name of p1 = " + p1.getName());
	}
	
}
