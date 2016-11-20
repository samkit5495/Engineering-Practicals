
public class SoftwareEngineer implements Employee {
	
	private String name;
	private double basicPay;	
	@Override
	public double grossPay() {
		// TODO Auto-generated method stub
		//System.out.println("Name:"+name);
		//System.out.println("Basic pay + 20% of basic pay as traveling allowance");
		return basicPay+0.2*basicPay;
	}
	@Override
	public String toString() {
		return "SoftwareEngineer [name=" + name + ", basicPay=" + basicPay
				+ "]\n";
	}
	public SoftwareEngineer(String name, double basicPay) {
		super();
		this.name = name;
		this.basicPay = basicPay;
	}

}
