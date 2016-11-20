import java.util.ArrayList;

public class TransportSystem {

	
	private ArrayList<BusDepo> depoList;
	private ArrayList<Employee> empList;
	public ArrayList<BusDepo> getDepoList() {
		return depoList;
	}
	public ArrayList<Employee> getEmpList() {
		return empList;
	}
	public TransportSystem() {
		super();
		// TODO Auto-generated constructor stub
		depoList=new ArrayList<>();
		empList=new ArrayList<>();
	}
	
	public void newDepo(BusDepo d)
	{
		depoList.add(d);
	}
	
	public void newEmployee(Employee e)
	{
		empList.add(e);
	}
	
	public BusDepo findBusDepo(String name)
	{
		for(BusDepo b:depoList)
		{
			if(b.getName().equals(name))
				return b;
		}
		return null;
	}
	

	
}
