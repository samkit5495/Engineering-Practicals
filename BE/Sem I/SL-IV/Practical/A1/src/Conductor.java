
public class Conductor extends Employee {

	
	@Override
	public String toString() {
		return "Conductor [machine=" + machine + ", getBadge()=" + getBadge() + ", getMobileNo()=" + getMobileNo()
				+ ", getAddress()=" + getAddress() + ", toString()=" + super.toString() + "]";
	}

	private TicketVendorMachine machine;
	
	public Conductor(Badge badge, String mobileNo, String address,TicketVendorMachine machine) {
		super(badge, mobileNo, address);
		// TODO Auto-generated constructor stub
		this.machine=machine;
	}

	public TicketVendorMachine getMachine() {
		return machine;
	}

	public void setMachine(TicketVendorMachine machine) {
		this.machine = machine;
	}

	public Conductor(Badge badge, String mobileNo, String address) {
		super(badge, mobileNo, address);
		// TODO Auto-generated constructor stub
	}
	
	
}
