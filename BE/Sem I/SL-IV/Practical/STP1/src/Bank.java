import java.util.ArrayList;

public class Bank {

	ArrayList<Credit_card> cardList;

	public Bank() {
		super();
		// TODO Auto-generated constructor stub
	cardList=new ArrayList<>();
	}
	
	public ArrayList<Credit_card> getCardList() {
		return cardList;
	}

	public void inputcard(Credit_card c)
	{
		cardList.add(c);
	}
	
	public void removecard(Credit_card c)
	{
		cardList.remove(c);
	}
	
	public void pay(Credit_card c, int amount)
	{
		c.pay(amount);
	}
	
	public int total_payback()
	{
		int a=0;
		for(Credit_card c:getCardList())
		{
			a+=c.payback();
		}return a;
	}
	
	

}
