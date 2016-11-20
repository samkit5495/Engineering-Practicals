import static org.junit.Assert.*;

import org.junit.Test;

public class FineTest {

	@Test
	public void test() {
		//fail("Not yet implemented");
		LibrarySystem l=new LibrarySystem();
		Book b=new Book("title","author");
		l.newBook(b);
		Person p=new Person("sam",1);
		l.newIssuer(p);
		
		l.issueBook(p, b);
		
		assertEquals(0, l.calFine(b));
		
	}

}
