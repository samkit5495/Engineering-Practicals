
public class InsufficientQuantity implements State {

	@Override
	public void doAction(String item, double amount) {
		// TODO Auto-generated method stub
		System.out.println(item +" cannot be deliveried due to inventory depletion");
	}

}
