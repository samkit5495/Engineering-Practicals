import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Receive implements Runnable{

	Socket socket;
	boolean server;
	public Receive(Socket socket,boolean server) {
		// TODO Auto-generated constructor stub
		this.socket=socket;
		this.server=server;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String msg="";
			while((msg=br.readLine())!=null){
				System.out.println((server?"Client":"Server")+": "+msg);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
