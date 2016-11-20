import java.util.Scanner;

public class Main {

	public static Scanner sc=new Scanner(System.in);
	public static void main(String args[])
	{
		AppraisalSystem as=new AppraisalSystem();
		do
		{
			as.promotion();	
			System.out.println("Enter 1 for Promotion and 0 to exit");
		}while(sc.nextInt()!=0);		
		sc.close();
	}
}
