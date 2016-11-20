import java.util.ArrayList;

public abstract class Account {

	protected String accNo;
	protected double balance;
	protected double interestRate;
	protected ArrayList<AccountHolder> accountHolders=new ArrayList<>(3);
	
	public boolean addAccountHolder(AccountHolder a)
	{
		if(accountHolders.size()<3)
		{
			accountHolders.add(a);
			a.addAccount(this);
			System.out.println("Account Holder Linked to account");
			return true;
		}
		else
			System.out.println("Account have reached its Account holder limit : 3.");
		return false;
	}
	
	public boolean addAccountHolder(AccountHolder a1,AccountHolder a2)
	{
		if(accountHolders.size()<2)
		{
			accountHolders.add(a1);
			a1.addAccount(this);
			accountHolders.add(a2);
			a2.addAccount(this);
			System.out.println("Account Holder Linked to account");
			return true;
		}
		else
			System.out.println("Account have reached its Account holder limit : 3.");
		return false;
	}
	
	public boolean addAccountHolder(AccountHolder a1,AccountHolder a2,AccountHolder a3)
	{
		if(accountHolders.size()<1)
		{
			a1.addAccount(this);
			accountHolders.add(a1);
			a2.addAccount(this);
			accountHolders.add(a2);
			a3.addAccount(this);
			accountHolders.add(a3);
			System.out.println("Account Holder Linked to account");
			return true;
		}
		else
			System.out.println("Account have reached its Account holder limit : 3.");
		return false;
	}
	
	
	@Override
	public String toString() {
		return "Account [accNo=" + accNo + ", balance=" + balance + ", interestRate=" + interestRate
				+ ", accountHolders=" + accountHolders.size() + "]\n";
	}
	public Account(String accNo, double balance, double interestRate) {
		super();
		this.accNo = accNo;
		this.balance = balance;
		this.interestRate = interestRate;
	}
	public String getAccNo() {
		return accNo;
	}
	public void setAccNo(String accNo) {
		this.accNo = accNo;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public double getInterestRate() {
		return interestRate;
	}
	public void setInterestRate(double interestRate) {
		this.interestRate = interestRate;
	}
	public ArrayList<AccountHolder> getAccountHolders() {
		return accountHolders;
	}
	public void deposit(double amount) {
		// TODO Auto-generated method stub
		balance+=amount;
		System.out.println("Amount Deposited\nCurrent Bal. "+balance);
	}
	public abstract void withdraw(double amount);
}
