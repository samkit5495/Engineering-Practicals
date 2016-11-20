import java.util.ArrayList;


public class Company {

	ArrayList<Employee> empList;

	public Company() {
		super();
		// TODO Auto-generated constructor stub
		this.empList=new ArrayList<Employee>();
		//empList=new ArrayList<Employee>();
	}

	public ArrayList<Employee> getEmpList() {
		return empList;
	}

	public void newEmployee(Employee e)
	{
		empList.add(e);
	}
	
	public void removeEmployee(Employee e)
	{
		empList.remove(e);
	}
	
	public double totalSalary()
	{
		double t=0;
		for(Employee e:empList)
		{
			t+=e.grossPay();
		}
		return t;
	}
	
	
}
