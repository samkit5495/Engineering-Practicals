
public class Program {
	
	public static void main(String[] args) {
		
		Bank b=new Bank();
		Account ac=new SavingAcc("1342", 15035, 5.9);
		AccountHolder a=new AccountHolder("samkit", "pune", "8600086024");
		b.newAccount(ac, a);

		ac.addAccountHolder(a);
		ac.addAccountHolder(a,a);
		ac.addAccountHolder(a);
		
		ac.deposit(500);
		
		ac.withdraw(500);
		
		ac.withdraw(50000);
		
		
		Account acc=new CurrentAcc("1352", 15035, 5.9);
		
		b.newAccount(acc, a);
		
		acc.deposit(100);
		
		acc.withdraw(50000);
		
		System.out.println("Accounts: ");
		System.out.println(b.getAccountList());
		
		System.out.println("Account Holder:");
		System.out.println(b.getAccountHolderList());
	}
}
