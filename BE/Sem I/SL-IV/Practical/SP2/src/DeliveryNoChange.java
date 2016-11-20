
public class DeliveryNoChange implements State {

	@Override
	public void doAction(String item, double amount) {
		// TODO Auto-generated method stub
		Item i=VendingMachine.vm.findItem(item);
		System.out.println(item+" given out with no change");
		i.setQuantity(i.getQuantity()-1);
	}

}
