import static org.junit.Assert.*;

import org.junit.Test;


public class Dimmer1 {

	@Test
	public void test() {
		//fail("Not yet implemented");
		Lamp l=new Lamp();
		l.setState(true);
		l.dimmer();
		assertEquals(2, l.getLevel());
	}

}
