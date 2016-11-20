
public class Gold implements Credit_card{

	private int points;
	
	
		public Gold() {
		super();
		// TODO Auto-generated constructor stub
		points=0;
	}

		public int payback() {
			// TODO Auto-generated method stub
			return points;
		}

		@Override
		public void pay(int amount) {
			// TODO Auto-generated method stub
			points+=(amount/100);
		}

}
