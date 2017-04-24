import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	
	public static void main(String[] args) throws IOException {
		
		int port=1234;
		System.out.println("Server Started at port 1234");
		@SuppressWarnings("resource")
		Socket clientSocket=new ServerSocket(port).accept();
		
		new Thread(new Receive(clientSocket,true)).start();
		
		new Thread(new Send(clientSocket,true)).start();
	}
}