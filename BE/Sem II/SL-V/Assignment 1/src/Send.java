import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class Send implements Runnable {
	
	Socket socket=null;
	boolean server;
	public Send(Socket socket,boolean server){
		this.socket=socket;
		this.server=server;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			String msg="";
			PrintWriter pw=new PrintWriter(new OutputStreamWriter(this.socket.getOutputStream()));
			while(true){
				BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
				System.out.println("Enter message to send to"+ (server? "Client":"Server"));
				while((msg=br.readLine())!=null)
				{
					pw.println(msg);
					pw.flush();
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}

}
