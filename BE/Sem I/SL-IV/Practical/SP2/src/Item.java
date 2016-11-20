
public class Item {

	private String name;
	private double amount;
	private int quantity;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getAmount() {
		return amount;
	}
	public void setAmount(double amount) {
		this.amount = amount;
	}
	public int getQuantity() {
		return quantity;
	}
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	public Item(String name, double amount, int quantity) {
		super();
		this.name = name;
		this.amount = amount;
		this.quantity = quantity;
	}
	public Item() {
		super();
		// TODO Auto-generated constructor stub
	}
	
}
