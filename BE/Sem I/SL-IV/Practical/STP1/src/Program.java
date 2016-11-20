
public class Program {

	public static void main(String args[])
	{
		Credit_card c1=new Classic();
		Credit_card s1=new Silver();
		Credit_card g1=new Gold();
		
		Bank b=new Bank();
		b.inputcard(c1);
		b.inputcard(s1);
		b.inputcard(g1);
		
		b.pay(c1, 50000);
		b.pay(s1, 50000);
		b.pay(g1, 70000);
		
		System.out.println("Total payback:"+b.total_payback());
	}
}
