
public class AppraisalSystem {

	private int rating;
	private State state;
	
	public AppraisalSystem() {
		// TODO Auto-generated constructor stub
		
		state=State.Worker;
	}
	
	public int getRating() {
		return rating;
	}

	public void setRating(int rating) {
		if(rating>=1&&rating<=5)
			this.rating = rating;
		else
			System.out.println("Invalid Rating");
	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}

	public void promotion()
	{
		System.out.println("Enter Rating:");
		this.setRating(Main.sc.nextInt());
		System.out.println("Current State:"+state);
		if(getRating()==1||getRating()==2)
			System.out.println("No increment");
		else if(getRating()==3||getRating()==4)
			System.out.println("10% increment");
		else
		{
			if(getState()==State.Worker)
				setState(State.Supervisor);
			else if(getState()==State.Supervisor)
				setState(State.Manager);
			System.out.println("Updated State: "+state);
			System.out.println("10% increment");
			
		}
	}
	
}
