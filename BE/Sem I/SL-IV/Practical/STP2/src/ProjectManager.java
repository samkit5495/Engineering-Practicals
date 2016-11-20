
public class ProjectManager implements Employee {
	@Override
	public String toString() {
		return "ProjectManager [name=" + name + ", basicPay=" + basicPay + "]\n";
	}

	private String name;
	private double basicPay;	
	
	public ProjectManager(String name, double basicPay) {
		super();
		this.name = name;
		this.basicPay = basicPay;
	}

	@Override
	public double grossPay() {
		// TODO Auto-generated method stub
		//System.out.println("Name:"+name);
		//System.out.println("Basic pay+ 40% of basic pay as traveling allowance + 40% of basic pay as on site allowance");
		return basicPay+0.4*basicPay+0.4*basicPay;
	}

}
