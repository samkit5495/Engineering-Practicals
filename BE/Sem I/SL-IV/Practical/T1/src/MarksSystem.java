import java.util.ArrayList;
import java.util.Scanner;

public class MarksSystem {

	private ArrayList<Student> studList;
	
	public MarksSystem() {
		super();
		// TODO Auto-generated constructor stub
		studList=new ArrayList<Student>();
	}
	
	public void analysis()
	{
		for(int i=0;i<5;i++)
		{
			int passed=0,failed=0,total=0,absent=0,present=0;
			for(Student s:studList)
			{
				total++;
				if(s.getSub()[i]==-1)
					absent++;
				else
					present++;
				if(s.getSub()[i]>=40)
					passed++;
				else
					failed++;
			}
			if(i==0)
				System.out.println("STQA: ");
			else if(i==1)
				System.out.println("OOMD: ");
			else if(i==2)
				System.out.println("MC: ");
			else if(i==3)
				System.out.println("AI: ");
			else 
				System.out.println("IAS: ");
			
			System.out.println("Passed: "+passed);
			System.out.println("Failed: "+failed);
			System.out.println("Present: "+present);
			System.out.println("Absent: "+absent);
			System.out.println("Result:"+((double)passed/total)*100);
		}
		
		
	}
	
	public void enterMarks(Student s)
	{
		Scanner sc=Program.sc;
		System.out.println("Enter -1 if Student Absent");
		System.out.print("STQA: ");
		s.getSub()[0]=sc.nextDouble();
		System.out.print("OOMD: ");
		s.getSub()[1]=sc.nextDouble();
		System.out.print("MC: ");
		s.getSub()[2]=sc.nextDouble();
		System.out.print("AI: ");
		s.getSub()[3]=sc.nextDouble();
		System.out.print("IAS: ");
		s.getSub()[4]=sc.nextDouble();
	}
	
	public Student findStudent(int rollNo)
	{
		for(Student s:studList)
		{
			if(s.getRollNo()==rollNo)
				return s;
		}
		return null;
	}

	public void newStudent(Student s)
	{
		studList.add(s);
	}
	
}
