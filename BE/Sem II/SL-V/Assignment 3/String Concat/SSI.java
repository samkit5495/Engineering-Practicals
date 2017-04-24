import java.rmi.*;

public interface SSI extends Remote
{
	String sum(String m, String n) throws RemoteException;
}