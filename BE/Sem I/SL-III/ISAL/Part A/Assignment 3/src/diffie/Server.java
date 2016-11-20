package diffie;
import java.io.*;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
 
public class Server
{
 
    private static Socket socket;
 
    public static void main(String[] args)
    {
        try
        {
            int port = 25000;
            @SuppressWarnings("resource")
			ServerSocket serverSocket = new ServerSocket(port);
            
            System.out.println("Server Started and listening to the port 25000");
            //Server is running always. This is done using this while(true) loop
            while(true)
            {
                //Reading the message from the client
                socket = serverSocket.accept();
                
                BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));

                // sending to client (pwrite object)
				OutputStream ostream = socket.getOutputStream(); 
				PrintWriter pwrite = new PrintWriter(ostream, true);
				
                // receiving from server ( receiveRead  object)
				InputStream istream = socket.getInputStream();
				BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
                
                BigInteger p=new BigInteger(receiveRead.readLine());
                BigInteger g=new BigInteger(receiveRead.readLine());
                BigInteger R1=new BigInteger(receiveRead.readLine());
                System.out.print("Enter value for y less than "+p+":");
                BigInteger y=new BigInteger(keyRead.readLine());
                
                System.out.println("R1="+R1);
                BigInteger R2=g.modPow(y,p);
                System.out.println("R2="+R2);
                
                pwrite.println(R2);
                
                BigInteger k2=R1.modPow(y,p);
                System.out.println("Key calculated at Bob's side:"+k2);
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                socket.close();
            }
            catch(Exception e){
            	e.printStackTrace();
            }
        }
    }
}