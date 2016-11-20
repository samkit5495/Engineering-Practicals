
public class CurrentAcc extends Account{

	public CurrentAcc(String accNo, double balance, double interestRate) {
		super(accNo, balance, interestRate);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void withdraw(double amount) {
		// TODO Auto-generated method stub
		balance-=amount;
		System.out.println("Balance Withdaw\nCurrent Bal. "+balance);
	}

}
