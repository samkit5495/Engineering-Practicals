import static org.junit.Assert.*;

import org.junit.Test;

/**
 * 
 */

/**
 * @author samki
 *
 */
public class TestLimit {

	@Test
	public void test() {
		//fail("Not yet implemented");
		LibrarySystem ls=new LibrarySystem();
		Book a=new Book("a","a");
		Book b=new Book("b","b");
		Book c=new Book("c","c");
		ls.newBook(a);
		ls.newBook(b);
		ls.newBook(c);
		
		Person p=new Person("sam",2);
		ls.newIssuer(p);
		
		ls.issueBook(p, a);
		ls.issueBook(p, b);
		ls.issueBook(p, c);
		
		assertEquals(0, p.getMaxBooks());
		
	}

}
