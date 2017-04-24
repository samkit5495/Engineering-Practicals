import java.net.*;
import java.rmi.*;

public class SS
{
	public static void main(String args[])
	{
		try
		{
			SSIm sumServerImpl=new SSIm();
			Naming.rebind("OP-SERVER",sumServerImpl);
		}
		catch(Exception e)
		{
			System.out.println("Exception:" +e);
		}
	}
}