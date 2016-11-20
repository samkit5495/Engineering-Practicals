
public class Student {

	private String name;
	private int rollNo;
	private double sub[]=new double[5];
	
	public Student() {
		super();
		// TODO Auto-generated constructor stub
	}
	public double[] getSub() {
		return sub;
	}
	public void setSub(double[] sub) {
		this.sub = sub;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getRollNo() {
		return rollNo;
	}
	public void setRollNo(int rollNo) {
		this.rollNo = rollNo;
	}
	public Student(String name, int rollNo) {
		super();
		this.name = name;
		this.rollNo = rollNo;
	}
	
}
