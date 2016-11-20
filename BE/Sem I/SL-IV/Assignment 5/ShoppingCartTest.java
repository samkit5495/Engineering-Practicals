public class Test
{
	public static void main(String[] args)
		{
			ShoppingCart cart = new ShoppingCart();
			Item item1 = new Item("A123",200);
			Item item2 = new Item("M8741",450);
			cart.addItem(item1);
			cart.addItem(item2);
		//pay by paytm
		cart.pay(new PaytmStrategy("asha123@gmail.com","asha1"));
	//pay by CreditCard
		cart.pay(new CreditCardStrategy("Madhav", "1234567890123456","9/18"));
	}
}
