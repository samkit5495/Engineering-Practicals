package Watch;

public class DigitalWatch {

	private State state;//state of digital watch
	private Time t;//time in the watch
	
	public DigitalWatch() {
		//default constructor to initialize
		super();
		// TODO Auto-generated constructor stub
		t=new Time();
		state=new DisplayTime();
	}

	public DigitalWatch(int hr,int min) {
		//Parameterized constructor to set time with given hr and min
		super();
		this.t = new Time(hr,min);
	}
	public DigitalWatch(Time t) {
		//parameterized constructor to set time with given time object
		super();
		this.t = t;
	}
	public void buttonA()
	{
		//if state in DisplayTime goto SetHours state
		if(state instanceof DisplayTime)
			doAction(new SetHours(),false);
		//if state in SetHours goto SetMinutes state
		else if(state instanceof SetHours)
			doAction(new SetMinutes(),false);
		//if state in SetMinutes goto DisplayTime state
		else
			doAction(new DisplayTime(),false);
	}

	public void buttonB()
	{
		//if state in DisplayTime NO change
		if(state instanceof DisplayTime)
			System.out.println("No Change");
		//if state in SetHours goto SetHours state
		else if(state instanceof SetHours)
			doAction(new SetHours(),true);
		//if state in SetMinutes goto SetMinutes state
		else
			doAction(new SetMinutes(),true);
	}

	/*doAction function to call doAction function of particular
	 *  state stored in state variable*/
	public void doAction()
	{
		state.doAction(t);
	}
	
	/*
	 * doAction function to call doAction function of particular
	 *  state stored in state variable with button code
	 * b=true A Button
	 * b=false B Button 
	 *  */
	public void doAction(boolean b)
	{
		state.doAction(t,b);
	}
	/*
	 * a combined function to set given state and and then call 
	 * doAction function of it
	 * */
	public void doAction(State s)
	{
		this.setState(s);
		this.doAction();
	}

	/*
	 a combined function to set given state and and then call 
	 * doAction function of it with button code
	 * b=true A Button
	 * b=false B Button
	 * */
	public void doAction(State s,boolean b)
	{
		this.setState(s);
		this.doAction(b);
	}
	//getter and setter of state and time variables
	public State getState() {
		return state;
	}
	public Time getT() {
		return t;
	}
	public void setState(State state) {
		this.state = state;
	}
	public void setT(Time t) {
		this.t = t;
	}
	
}
