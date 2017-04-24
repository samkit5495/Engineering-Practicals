import java.rmi.*;


public class SC
{
	public static void main(String args[])
	{
		try
		{
			String sumServerURL="rmi://" +args[0]+ "/SUM-SERVER";
			SSI sumServerIntf=(SSI)Naming.lookup(sumServerURL);
			System.out.println("The first string is:" +args[1]);
			String m=args[1];
			System.out.println("The second string is:" +args[2]);
			String n=args[2];
			System.out.println("The sum is:" +sumServerIntf.sum(m,n));
		
		}
		catch(Exception e)
		{
			System.out.println("Exception" +e);
		
		}
	}
}