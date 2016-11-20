
public class Bus {
	
	private String chasisNo;
	private String busNo;
	private Conductor c;
	private Driver d;
	
	public String getChasisNo() {
		return chasisNo;
	}
	public void setChasisNo(String chasisNo) {
		if(chasisNo.length()==8)
			this.chasisNo = chasisNo;
		else
			System.out.println("Invalid Chassis No");
	}
	@Override
	public String toString() {
		return "Bus [chasisNo=" + chasisNo + ", busNo=" + busNo + ", c=" + c + ", d=" + d + "]";
	}
	public String getBusNo() {
		return busNo;
	}
	public void setBusNo(String busNo) {
		if(busNo.length()==4)
			this.busNo = busNo;
		else
			System.out.println("Invalid Bus no");
	}
	public Conductor getC() {
		return c;
	}
	public void setC(Conductor c) {
		this.c = c;
	}
	public Driver getD() {
		return d;
	}
	public void setD(Driver d) {
		this.d = d;
	}
	
	public Bus(String chasisNo, String busNo, Conductor c, Driver d) {
		super();
		if(chasisNo.length()==8&&busNo.length()==4)
		{
			this.chasisNo = chasisNo;
			this.busNo = busNo;
			this.c = c;
			this.d = d;
		}
		else
			System.out.println("Invalid Chassis or bus no");
		
	}
	

}
