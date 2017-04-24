import java.rmi.*;

public class SC
{
	public static void main(String args[])
	{
		try
		{
			System.out.println("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
			System.out.println("<ip-address> <op> <num1> <num2>");
			String opServerURL="rmi://" +args[0]+ "/OP-SERVER";
			SSI opServerIntf=(SSI)Naming.lookup(opServerURL);
			System.out.println("The first number is:" +args[2]);
			int m=Integer.valueOf(args[2]);
			System.out.println("The second number is:" +args[3]);
			int n=Integer.valueOf(args[3]);
			switch(Integer.valueOf(args[1]))
			{
				case 1:
					System.out.println("The addition is:" +opServerIntf.add(m,n));
					break;
				case 2:
					System.out.println("The subtraction is:" +opServerIntf.subtract(m,n));
					break;
				case 3:
					System.out.println("The multiplication is:" +opServerIntf.multiply(m,n));
					break;
				case 4:
					System.out.println("The division is:" +opServerIntf.divide(m,n));
					break;
			}		
		}
		catch(Exception e)
		{
			System.out.println("Exception" +e);
		
		}
	}
}