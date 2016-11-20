
public abstract class Employee {

	private Badge badge;//association1..1
	private String mobileNo;
	private String address;
	public Badge getBadge() {
		return badge;
	}
	public void setBadge(Badge badge) {
		this.badge = badge;
	}
	public String getMobileNo() {
		return mobileNo;
	}
	public void setMobileNo(String mobileNo) {
		this.mobileNo = mobileNo;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public Employee(Badge badge, String mobileNo, String address) {
		super();
		this.badge = badge;
		this.mobileNo = mobileNo;
		this.address = address;
	}
	
}
