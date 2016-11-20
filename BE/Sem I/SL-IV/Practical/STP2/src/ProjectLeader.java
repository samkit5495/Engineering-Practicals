
public class ProjectLeader implements Employee {
	private String name;
	private double basicPay;	
	
	public ProjectLeader(String name, double basicPay) {
		super();
		this.name = name;
		this.basicPay = basicPay;
	}

	@Override
	public double grossPay() {
		// TODO Auto-generated method stub
		//System.out.println("Name:"+name);
		//System.out.println("Basic pay+ 30% of basic pay as traveling allowance + 30% of basic pay as on site allowance");
		return basicPay+0.3*basicPay+0.3*basicPay;

	}

	@Override
	public String toString() {
		return "ProjectLeader [name=" + name + ", basicPay=" + basicPay + "]\n";
	}

}
