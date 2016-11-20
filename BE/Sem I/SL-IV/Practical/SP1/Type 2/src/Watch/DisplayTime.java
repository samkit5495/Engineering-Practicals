package Watch;

public class DisplayTime implements State {

	//only display time to user
	public void doAction(Time t) {
		// TODO Auto-generated method stub
		System.out.println(this.getClass());
		System.out.println(t);
	}

	public void doAction(Time t, boolean b) {
		// TODO Auto-generated method stub
		doAction(t);
	}

}
