
public class Driver extends Employee{
	
	public Driver(Badge badge, String mobileNo, String address) {
		super(badge, mobileNo, address);
		// TODO Auto-generated constructor stub
	}

	@Override
	public String toString() {
		return "Driver [getBadge()=" + getBadge() + ", getMobileNo()=" + getMobileNo() + ", getAddress()="
				+ getAddress() + ", toString()=" + super.toString() + "]";
	}
	

	
}
