import static org.junit.Assert.*;

import org.junit.Test;

public class BookTest {

	@Test
	public void test() {
		//fail("Not yet implemented");
		LibrarySystem ls=new LibrarySystem();
		Book b=new Book("title","author");
		ls.newBook(b);
		Person p=new Person("Sam",3);
		ls.newIssuer(p);
		
		ls.issueBook(p, b);
		
		assertEquals(false, ls.bookAvailable("title"));
	}

}
