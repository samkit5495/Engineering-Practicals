import java.util.Scanner;

public class Program {

	public static Scanner sc=new Scanner(System.in);
	public static int menu()
	{
		System.out.println("0. Exit");
		System.out.println("1. Add Student");
		System.out.println("2. Enter Marks");
		System.out.println("3. Analysis");
		return sc.nextInt();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MarksSystem ms=new MarksSystem();
		int ch;
		Student s;
		while((ch=menu())!=0)
		{
			switch(ch)
			{
			case 1:
				s=new Student();
				System.out.print("Enter Roll No");
				s.setRollNo(sc.nextInt());
				System.out.print("Enter Name: ");
				s.setName(sc.next());
				ms.newStudent(s);
				System.out.println("Student Added");
				break;
			case 2:
				System.out.print("Enter Student Roll No:");
				s=ms.findStudent(sc.nextInt());
				if(s==null)
					System.out.println("Student Not Found!!!");
				else
					ms.enterMarks(s);
				break;
			case 3:
				ms.analysis();
				break;
			}
		}
		
	}

}
