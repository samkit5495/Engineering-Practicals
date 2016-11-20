
public class TicketVendorMachine {

	private int id;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	@Override
	public String toString() {
		return "TicketVendorMachine [id=" + id + "]";
	}
	public TicketVendorMachine(int id) {
		super();
		this.id = id;
	}

	
}
