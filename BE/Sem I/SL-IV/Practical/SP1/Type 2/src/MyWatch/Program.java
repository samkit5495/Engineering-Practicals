package MyWatch;
import java.util.Scanner;
import Watch.*;

public class Program {

	/**
	 * @param args
	 */
	public static Scanner sc=new Scanner(System.in);
	public static int menu()
	{
		System.out.println("0. Exit");
		System.out.println("1. Button A");
		System.out.println("2. Button B");
		return sc.nextInt();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ch;
		DigitalWatch d=new DigitalWatch();
		d.doAction();
		while((ch=menu())!=0)
		{
			switch(ch)
			{
			case 1:
				d.buttonA();
				break;
			case 2:
				d.buttonB();
				break;
			default:
				System.out.println("Invalid Choice!!!");
				break;
			}	
		}
		
	}

}
