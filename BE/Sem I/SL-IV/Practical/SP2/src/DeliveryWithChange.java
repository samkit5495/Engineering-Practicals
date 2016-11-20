
public class DeliveryWithChange implements State {

	@Override
	public void doAction(String item, double amount) {
		// TODO Auto-generated method stub
		Item i=VendingMachine.vm.findItem(item);
		System.out.println(item+" given out with change "+(amount-i.getAmount()));
		i.setQuantity(i.getQuantity()-1);
	}

}
