package Watch;

public interface State {

	//a action function of state with only time
	public void doAction(Time t);
	/*
	 a action function of state with time & button code
	 * b=true A Button
	 * b=false B Button
	 * */
	public void doAction(Time t,boolean b);
}
