import java.util.ArrayList;

public class VendingMachine {

	private ArrayList<Item> itemList;
	private State state;
	public static VendingMachine vm=new VendingMachine();
	private VendingMachine() {
		super();
		// TODO Auto-generated constructor stub
		itemList=new ArrayList<>();
	}
	
	
	public void newItem(Item i)
	{
		itemList.add(i);
	}
	
	public void removeItem(Item i)
	{
		itemList.remove(i);
	}
	
	public Item findItem(String name)
	{
		for(Item i:itemList)
		{
			if(i.getName().equals(name))
				return i;
		}
		return null;
	}
	
	public void insertMoney(String name,double amount)
	{
		Item i=findItem(name);
		if(i!=null)
		{
			if(i.getQuantity()<=0)
				state=new InsufficientQuantity();
			else if(i.getAmount()==amount)
				state=new DeliveryNoChange();
			else if(i.getAmount()<amount)
				state=new DeliveryWithChange();
			else if(i.getAmount()>amount)
				state=new InsufficientBalance();

			state.doAction(name, amount);
		}
		else
			System.out.println("Item Not Found");
	}
	
}
