
public class SavingAcc extends Account {



	public SavingAcc(String accNo, double balance, double interestRate) {
		super(accNo, balance, interestRate);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void withdraw(double amount) {
		// TODO Auto-generated method stub
		if(balance>=amount)
		{
			balance-=amount;
			System.out.println("Balance Withdaw\nCurrent Bal. "+balance);
		}
		else
			System.out.println("Cannot withdraw insufficient balance");
	}

}
