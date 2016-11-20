
public class InsufficientBalance implements State {

	@Override
	public void doAction(String item, double amount) {
		// TODO Auto-generated method stub
		double remaining=VendingMachine.vm.findItem(item).getAmount()-amount;
		System.out.println(item+" cannot be purchased with balance "+amount+" need more "+remaining);
	}

}
