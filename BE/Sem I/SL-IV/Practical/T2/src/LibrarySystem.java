import java.util.ArrayList;
import java.util.Date;

public class LibrarySystem {

	private ArrayList<Book> bookList;
	private ArrayList<Person> issuerList;
	public LibrarySystem() {
		super();
		// TODO Auto-generated constructor stub
		bookList=new ArrayList<>();
		issuerList=new ArrayList<>();
	}
	
	public void newBook(Book b)
	{
		this.bookList.add(b);
		System.out.println("Book Added!!!");
	}
	
	public void newIssuer(Person p)
	{
		this.issuerList.add(p);
		System.out.println("Issuer Added!!!");
	}
	
	public void issueBook(Person p,Book b)
	{
		if(b.getIssuer()==null && p.getMaxBooks()>0)
		{
			b.setIssuer(p);
			b.setIssueDate(new Date());
			p.setMaxBooks(p.getMaxBooks()-1);
			System.out.println("Book Issued!!!");
		}
		else
			System.out.println("Book Already Issued");
	}
	
	public Person findIssuer(String name)
	{
		for(Person p:issuerList)
		{
			if(p.getName().equals(name))
				return p;
		}
		return null;
	}
	
	public Book findBook(String title)
	{
		for(Book b:bookList)
		{
			if(b.getTitle().equals(title))
				return b;
		}
		return null;
	}
	
	public void returnBook(Person p,Book b)
	{
		if(b.getIssuer()==null)
			System.out.println("Book not yet issued!!!");
		else
		{
			System.out.println("Fine 10 Rs per day: "+calFine(b));
			b.setIssuer(null);
			b.setIssueDate(null);
			p.setMaxBooks(p.getMaxBooks()+1);
			System.out.println("Book Returned!!!");
		}
	}
	
	public int calFine(Book b)
	{
		long days=(new Date().getTime()-b.getIssueDate().getTime())/(24 * 60 * 60 * 1000);
		if(days>7)
			return (int) (10*(days-7));
		else
			return 0;
	}
	
	public boolean bookAvailable(String title)
	{
		Book b=findBook(title);
		if(b==null)
		{
			System.out.println("Book not found");
			return false;
		}
		if(b.getIssuer()==null)
			return true;
		else
			return false;
	}
	
	
	
}
