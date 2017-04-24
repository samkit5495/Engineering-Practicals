import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	
	public static void main(String[] args) throws UnknownHostException, IOException {
		
		Socket socket=new Socket("localhost", 1234);
		new Thread(new Send(socket,false)).start();
		new Thread(new Receive(socket,false)).start();
	}

}
