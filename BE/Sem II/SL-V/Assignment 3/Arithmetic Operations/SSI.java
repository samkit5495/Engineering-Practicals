import java.rmi.*;

public interface SSI extends Remote
{
	int add(int m, int n) throws RemoteException;
	int subtract(int m, int n) throws RemoteException;
	int multiply(int m, int n) throws RemoteException;
	int divide(int m, int n) throws RemoteException;
}