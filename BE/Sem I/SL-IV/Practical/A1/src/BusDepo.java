import java.util.ArrayList;

public class BusDepo {

	private String name;
	private ArrayList<Bus> busList;

	public String getName() {
		return name;
	}

	@Override
	public String toString() {
		return "BusDepo [name=" + name + "]";
	}

	public void setName(String name) {
		this.name = name;
	}

	public ArrayList<Bus> getBusList() {
		return busList;
	}

	public BusDepo() {
		super();
		// TODO Auto-generated constructor stub
		busList=new ArrayList<>();
	}
	
	public BusDepo(String name) {
		super();
		this.name = name;
		busList=new ArrayList<>();
	}

	public void newBus(Bus b)
	{
		busList.add(b);
	}
	
	
}
