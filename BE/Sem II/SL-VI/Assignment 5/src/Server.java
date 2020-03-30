
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
	
	List<ClientThread> ctList;
	List<String> data;
	boolean closed=false;
	boolean inputFromAll=false;
	public Server() {
		// TODO Auto-generated constructor stub
		ctList=new ArrayList<>();
		data=new ArrayList<>();
	}
	
	public static void main(String[] args) {
		

		ServerSocket socket=null;
		Socket clientSocket=null;
		int port_number=8989;
		
		Server server=new Server();

		try{
			socket=new ServerSocket(port_number);	
		}
		catch (IOException e)
		{
			System.out.println(e);
		}

		
		while(!server.closed){
			try
			{
				clientSocket=socket.accept();
				ClientThread th=new ClientThread(clientSocket, server);
				server.ctList.add(th);
				System.out.println("No of Client Connected: "+server.ctList.size());
				server.data.add("NOT SENT");
				th.start();
			}
			catch(IOException e){}
		}
		try{
			socket.close();
		}
		catch(Exception e){}
		
	}

}

class ClientThread extends Thread{
	
	Socket clientSocket=null;
	Server server=null;
	DataInputStream is=null;
	PrintStream os=null;
	String name;
	public ClientThread(Socket clientSocket, Server server) throws IOException {
		super();
		this.clientSocket = clientSocket;
		this.server = server;		
	}
	
	@SuppressWarnings("deprecation")
	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			is=new DataInputStream(clientSocket.getInputStream());
			os=new PrintStream(clientSocket.getOutputStream());
			os.println("Enter your name: ");
			name=is.readLine();
			System.out.println("Client connected: "+name);
			for(ClientThread t:server.ctList)
				if(t!=this)
					t.os.println("A new client named "+name+"is connected to the system");
			os.println("Enter COMMIT/ABORT");
			while(true)
			{
				String message=is.readLine();
				// System.out.println(name+" : "+message);
				if(message.equalsIgnoreCase("ABORT"))
				{
					
					for(ClientThread t:server.ctList)
					{
						t.os.println("GLOBAL ABORT");
						t.is.close();
						t.os.close();
					}
					System.out.println("GLOBAL ABORT");
					
					break;
				}
				else if(message.equalsIgnoreCase("COMMIT"))
				{
					if((server.ctList).contains(this))
					{
						server.data.set(server.ctList.indexOf(this), "COMMIT");
						for(String d:server.data)
						{
							if(!d.equalsIgnoreCase("NOT SENT"))
								server.inputFromAll=true;
							else
							{
								server.inputFromAll=false;
								System.out.println("\nWaiting for inputs from other clients.");
								break;
							}
						}
						if(server.inputFromAll)
						{
							System.out.println("GLOBAL COMMIT");
							for(ClientThread t:server.ctList)
							{
								t.os.println("GLOBAL COMMIT");
								t.is.close();
								t.os.close();
							}
													
							break;
						}
					}				
				}
			}
			server.closed=true;
			clientSocket.close();
			
			
		} catch (Exception e) {	};
	}
}
