
public class Person {

	private String name;
	private int maxBooks=0;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getMaxBooks() {
		return maxBooks;
	}
	public void setMaxBooks(int maxBooks) {
		this.maxBooks = maxBooks;
	}
	public Person() {
		super();
		// TODO Auto-generated constructor stub
	}
	public Person(String name, int maxBooks) {
		super();
		this.name = name;
		this.maxBooks = maxBooks;
	}
	
}
