package diffie;
import java.io.*;
import java.math.BigInteger;
import java.net.Socket;
 
public class Client
{
 
    private static Socket socket;
 
    public static void main(String args[])
    {
        try
        {
            int port = 25000;
            socket = new Socket("127.0.0.1", port);
 
            //Send the message to the server
            BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));

            // sending to client (pwrite object)
			OutputStream ostream = socket.getOutputStream(); 
			PrintWriter pwrite = new PrintWriter(ostream, true);

            // receiving from server ( receiveRead  object)
			InputStream istream = socket.getInputStream();
			BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
			
            System.out.println("Enter prime number:");
            BigInteger p=new BigInteger(keyRead.readLine());
            System.out.print("Enter primitive root of "+p+":");
            BigInteger g=new BigInteger(keyRead.readLine());
            
            System.out.println("Enter value for x less than "+p+":");
            BigInteger x=new BigInteger(keyRead.readLine());
            BigInteger R1=g.modPow(x,p);
            System.out.println("R1="+R1);
            
            pwrite.println(p);
            pwrite.println(g);
            pwrite.println(R1);
            
            BigInteger R2=new BigInteger(receiveRead.readLine());
            
            System.out.println("R2="+R2);
            
            BigInteger k1=R2.modPow(x,p);
            System.out.println("Key calculated at Alice's side:"+k1);
        }
        catch (Exception exception)
        {
            exception.printStackTrace();
        }
        finally
        {
            //Closing the socket
            try
            {
                socket.close();
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
    }
}