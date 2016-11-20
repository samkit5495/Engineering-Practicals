
public class Classic implements Credit_card{

	private int points;
	
	public Classic() {
		super();
		points=0;
		// TODO Auto-generated constructor stub
	}

	@Override
	public int payback() {
		// TODO Auto-generated method stub
		return points;
	}

	@Override
	public void pay(int amount) {
		// TODO Auto-generated method stub
		points+=(amount/200);
	}

}
