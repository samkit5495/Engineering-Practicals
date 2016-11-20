import static org.junit.Assert.*;

import org.junit.Test;

public class TestStudentList {

	@Test
	public void test() {
		//fail("Not yet implemented");
		MarksSystem ms=new MarksSystem();
		Student s=new Student("Sam",1);
		ms.newStudent(s);
		assertEquals("Sam", ms.findStudent(1).getName());
	}

}
