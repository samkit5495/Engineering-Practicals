import java.util.ArrayList;

public class AccountHolder {

	private String name;
	private String address;
	private String mobNo;
	private ArrayList<Account> accounts=new ArrayList<>();
	
	public void addAccount(Account a)
	{
		this.accounts.add(a);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getMobNo() {
		return mobNo;
	}

	public void setMobNo(String mobNo) {
		this.mobNo = mobNo;
	}

	public ArrayList<Account> getAccounts() {
		return accounts;
	}

	@Override
	public String toString() {
		return "AccountHolder [name=" + name + ", address=" + address + ", mobNo=" + mobNo + ", accounts=" + accounts
				+ "]\n";
	}

	public AccountHolder(String name, String address, String mobNo) {
		super();
		this.name = name;
		this.address = address;
		this.mobNo = mobNo;
	}
	
}
