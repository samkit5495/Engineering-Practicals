
public class Program {

	public static void main(String[] args) {
		
		VendingMachine.vm.newItem(new Item("Mirinda", 30, 3));
		System.out.println(VendingMachine.vm.findItem("Mirinda").getQuantity());
		VendingMachine.vm.insertMoney("Mirinda", 30);
		System.out.println(VendingMachine.vm.findItem("Mirinda").getQuantity());
		VendingMachine.vm.insertMoney("Mirinda", 40);
		System.out.println(VendingMachine.vm.findItem("Mirinda").getQuantity());
		VendingMachine.vm.insertMoney("Mirinda", 20);
		System.out.println(VendingMachine.vm.findItem("Mirinda").getQuantity());
		VendingMachine.vm.insertMoney("Mirinda", 30);
		System.out.println(VendingMachine.vm.findItem("Mirinda").getQuantity());
		VendingMachine.vm.insertMoney("Mirinda", 30);
	}
}
