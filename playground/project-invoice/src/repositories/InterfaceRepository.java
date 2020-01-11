package repositories;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public interface InterfaceRepository<Type> {
	
	public int size();
	
	public Type get(int index);
	
	public void add (Type element);
	public void add (Type element, int index);
	
	public void update (Type element, int index);
	public void update(Type old, Type newElement);
	
	public void loadFromFile(FileInputStream file) throws IOException, ClassNotFoundException;
	public void saveOnFile(FileOutputStream file) throws IOException;
	
	public Type remove (Type element);
	public Type remove (int index);
	
	public int search (Type element);
	

}
