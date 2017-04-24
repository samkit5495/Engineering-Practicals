import java.rmi.*;
import java.rmi.server.*;

public class SSIm extends UnicastRemoteObject implements SSI
{
	public SSIm() throws RemoteException{}
	
	public String sum(String m, String n) throws RemoteException
	{
		return m+n;
	}
}
