package repositories;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collection;

public class Repository<Type> implements InterfaceRepository<Type> {
	
	private ArrayList<Type> elements;
	
	public Repository() {
		this.elements = new ArrayList<Type>();
	}
	
	public Repository(ArrayList<Type> elements) {
		this.elements = elements;
	}
	
	
	public Type get(int index) {
		if( index < 0 || index > this.elements.size() ) 
			return null;
		
		return this.elements.get(index);
	}
	
	
	public int size() {
		return this.elements.size();
	}
	
	public void setElements(ArrayList<Type> elements) {
		this.elements = elements;
	}
	
	
	public ArrayList<Type> getElements() {
		return this.elements;
	}
	
	
	public void add(Type element) {
		this.elements.add(element);
	}
	
	public void add(Type element, int index) {
		this.elements.add(index, element);
	}
	
	
	public void update(Type element, int index) {
		this.remove(index);
		this.add(element, index);
	}
	
	public void update(Type old, Type newElement) {
		int index = this.search(old);
		
		if(index == -1)
			return;
		
		this.remove(index);
		this.add(newElement, index);
	}
	
	
	public void loadFromFile(FileInputStream file) throws IOException, ClassNotFoundException {
		ObjectInputStream loader = null;
			
		loader = new ObjectInputStream(file);
		
		this.elements.addAll( (Collection<? extends Type>) loader.readObject() );

		if(loader != null)
			loader.close();
	}
	
	public void saveOnFile(FileOutputStream file) throws IOException {
		ObjectOutputStream saver = null;
		
		saver = new ObjectOutputStream(file);
		
		saver.writeObject(this.elements);
		
		saver.flush();
		file.flush();
		if(saver != null)
			saver.close();
		
	}
	
	
	public Type remove (Type element) {
		int index = this.search(element);
		
		if (index == -1)
			return null;
		
		this.elements.remove(index);
		
		return element;
	}
	
	public Type remove (int index) {
		if (index < 0 || index >= this.elements.size())
			return null;
		
		Type element= this.elements.get(index);
				
		this.elements.remove(index);
		
		return element;
	}

	
	public int search (Type element) {
		for (int k = 0; k < this.elements.size(); k++) {
			if (this.elements.get(k).equals(element))
				return k;
		}
		
		return -1;
	}
	
	
}
