
public class Digital_Watch {

	private State state;//aggregation
	private int hr,min;
	public Digital_Watch(int hr,int min) {
		super();
		this.hr=hr;
		this.min=min;
		state=new Display_time();
		// TODO Auto-generated constructor stub
	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}
	
	public void doAction()
	{
		if(state instanceof Set_Minutes)
			min=state.doAction(hr,min);
		else if(state instanceof Set_hours)
			hr=state.doAction(hr, min);
		else
			state.doAction(hr, min);
			
	}
}
