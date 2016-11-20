import static org.junit.Assert.*;

import org.junit.Test;


public class Dimmer {

	@Test
	public void test() {
		//fail("Not yet implemented");
		Lamp l=new Lamp();
		l.dimmer();
		assertEquals(1, l.getLevel());
	}

}
