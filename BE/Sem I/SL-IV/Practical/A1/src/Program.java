

public class Program {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TransportSystem ts=new TransportSystem();
		
		
		BusDepo swargate=new BusDepo("Swargate");
		
		ts.newDepo(swargate);
		
		Badge ba1=new Badge(1, "sam");
		Conductor c=new Conductor(ba1, "1324657890","Pune",new TicketVendorMachine(1));
		Badge ba2=new Badge(2, "sam");
		Driver d=new Driver(ba2, "1111111111","Pune");
		
		Bus b1 =new Bus("12346578","1234",c,d);
		Bus b2=new Bus("12346578","1234",c,d);
		swargate.newBus(b1);
		swargate.newBus(b2);
		
		BusDepo shivaginagar=new BusDepo("Shivaginagar");
		
		ts.newDepo(shivaginagar);
		
		Bus b3=new Bus("12346578","1234",c,d);
		Bus b4=new Bus("12346578","1234",c,d);
		shivaginagar.newBus(b3);
		shivaginagar.newBus(b4);
		
		System.out.println("Deops:" +ts.getDepoList());
		System.out.println("Buses");
		for(BusDepo bd:ts.getDepoList())
		{
			for(Bus b:bd.getBusList())
				System.out.println("Busses"+b);
		}
	}

}
