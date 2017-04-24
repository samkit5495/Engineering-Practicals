
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client extends Thread {

	static boolean closed=false;
	static DataInputStream is=null;
	static PrintStream os=null;
	public static void main(String[] args) throws UnknownHostException, IOException {
		
		Socket serverSocket=new Socket("localhost",8989);
		is=new DataInputStream(serverSocket.getInputStream());
		os=new PrintStream(serverSocket.getOutputStream());
		BufferedReader console=new BufferedReader(new InputStreamReader(System.in));
		new Client().start();
		if(serverSocket!=null && is!=null && os !=null)
		{
			while(!closed)
			{
				os.println(console.readLine());
			}
			is.close();
			os.close();
			serverSocket.close();
		}
	}
	
	@SuppressWarnings("deprecation")
	@Override
	public void run() {
		// TODO Auto-generated method stub
		String serverResponse=null;	
		try {
			while((serverResponse=is.readLine())!=null)
			{
				System.out.println(serverResponse);
				if(serverResponse.equalsIgnoreCase("GLOBAL ABORT")||serverResponse.equalsIgnoreCase("GLOBAL COMMIT"))
					break;
			}
			Client.closed=true;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
