import java.util.ArrayList;

public class Company {

	private String name;
	private int salary;
	private String position;
	private int criteria;
	private ArrayList<Candidate> shortList;
	public Company() {
		super();
		shortList=new ArrayList<>();
		// TODO Auto-generated constructor stub
	}
	public Company(String name, int salary, String position, int criteria) {
		super();
		this.name = name;
		this.salary = salary;
		this.position = position;
		this.criteria = criteria;
		shortList=new ArrayList<>();
	}
	
	public int getCriteria() {
		return criteria;
	}
	public String getName() {
		return name;
	}
	public String getPosition() {
		return position;
	}
	public int getSalary() {
		return salary;
	}
	public ArrayList<Candidate> getShortList() {
		return shortList;
	}
	public void setCriteria(int criteria) {
		this.criteria = criteria;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setPosition(String position) {
		this.position = position;
	}
	public void setSalary(int salary) {
		this.salary = salary;
	}
	@Override
	public String toString() {
		return "Company [name=" + name + ", salary=" + salary + ", position=" + position + ", criteria=" + criteria
				+ "]\n";
	}
	public void selectionLetter()
	{
		System.out.println("Selection letter send to: ");
		System.out.println(this.getShortList());
	}
	public void schedule()
	{
		System.out.println("Schedule send to: ");
		System.out.println(this.getShortList());
	}
}
