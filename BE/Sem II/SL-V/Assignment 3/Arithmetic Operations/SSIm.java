import java.rmi.*;
import java.rmi.server.*;

public class SSIm extends UnicastRemoteObject implements SSI
{
	public SSIm() throws RemoteException{}

	public int add(int m, int n) throws RemoteException
	{
		return m+n;
	}
	public int subtract(int m, int n) throws RemoteException
	{
		return m-n;
	}
	public int multiply(int m, int n) throws RemoteException
	{
		return m*n;
	}
	public int divide(int m, int n) throws RemoteException
	{
		return m/n;
	}
}
