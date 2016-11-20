import java.util.ArrayList;

public class Candidate {

	private int id;
	private String name;
	private String mailID;
	private String mob;
	private int aggregate;
	private ArrayList<Company> registered;
	
	public void register(Company c)
	{
		if(this.getAggregate()>=c.getCriteria())
		{
			registered.add(c);
			c.getShortList().add(this);
			System.out.println(this.getName()+" Successfully registered for "+c.getName());
		}
		else
			System.out.println("Not Eligible");
		
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getMailID() {
		return mailID;
	}
	public void setMailID(String mailID) {
		this.mailID = mailID;
	}
	public String getMob() {
		return mob;
	}
	public void setMob(String mob) {
		this.mob = mob;
	}
	public int getAggregate() {
		return aggregate;
	}
	public void setAggregate(int aggregate) {
		this.aggregate = aggregate;
	}
	public Candidate(int id, String name, String mailID, String mob, int aggregate) {
		super();
		this.id = id;
		this.name = name;
		this.mailID = mailID;
		this.mob = mob;
		this.aggregate = aggregate;
		registered=new ArrayList<>();
	}
	public Candidate() {
		super();
		registered=new ArrayList<>();
		// TODO Auto-generated constructor stub
	}
	@Override
	public String toString() {
		return "Candidate [id=" + id + ", name=" + name + ", mailID=" + mailID + ", mob=" + mob + ", aggregate="
				+ aggregate + "]\n";
	}
	
}
