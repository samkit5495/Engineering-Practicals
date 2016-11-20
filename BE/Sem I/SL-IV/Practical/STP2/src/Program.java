import java.math.BigDecimal;


public class Program {

	public static void main(String[] args) {
		
		Company microsoft=new Company();
		
		Employee e1=new SoftwareEngineer("Samkit", 35000);
		microsoft.newEmployee(e1);
		Employee e2=new SoftwareEngineer("Samkit", 35000);
		microsoft.newEmployee(e2);
		Employee e3=new SoftwareEngineer("Samkit", 35000);
		microsoft.newEmployee(e3);
		Employee e4=new SoftwareEngineer("Samkit", 35000);
		microsoft.newEmployee(e4);
		
		Employee e5=new ProjectLeader("Samkit", 35000);
		microsoft.newEmployee(e5);
		Employee e6=new ProjectLeader("Samkit", 35000);
		microsoft.newEmployee(e6);
		
		Employee e7=new ProjectManager("Samkit", 35000);
		microsoft.newEmployee(e7);
		
		System.out.println(microsoft.getEmpList());
		
		BigDecimal t=new BigDecimal(microsoft.totalSalary());
		
		System.out.println("Total Pay of Company: "+t);
	}
}
