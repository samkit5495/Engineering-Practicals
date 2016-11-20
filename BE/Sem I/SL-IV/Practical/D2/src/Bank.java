import java.util.ArrayList;

public class Bank {

	private ArrayList<Account> accountList;
	private ArrayList<AccountHolder> accountHolderList;
	
	
	public Bank() {
		super();
		// TODO Auto-generated constructor stub
		accountHolderList=new ArrayList<>();
		accountList=new ArrayList<>();
	}

	public ArrayList<Account> getAccountList() {
		return accountList;
	}

	public void setAccountList(ArrayList<Account> accountList) {
		this.accountList = accountList;
	}

	public ArrayList<AccountHolder> getAccountHolderList() {
		return accountHolderList;
	}

	public void setAccountHolderList(ArrayList<AccountHolder> accountHolderList) {
		this.accountHolderList = accountHolderList;
	}

	public void newAccount(Account a,AccountHolder a1)
	{
		if(a.addAccountHolder(a1))
		{
			accountList.add(a);
			accountHolderList.add(a1);
		}
		
	}
	
	public void newAccount(Account a,AccountHolder a1,AccountHolder a2)
	{
		if(a.addAccountHolder(a1,a2))
		{
			accountList.add(a);
			accountHolderList.add(a1);
			accountHolderList.add(a2);
		}
	}
	
	public void newAccount(Account a,AccountHolder a1,AccountHolder a2,AccountHolder a3)
	{
		if(a.addAccountHolder(a1,a2,a3))
		{
			accountList.add(a);
			accountHolderList.add(a1);
			accountHolderList.add(a2);
			accountHolderList.add(a3);
		}
	}
	
	public void addAccountHolder(Account a,AccountHolder a1)
	{
		a.addAccountHolder(a1);
	}
}
