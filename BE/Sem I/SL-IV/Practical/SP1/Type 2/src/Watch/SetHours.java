package Watch;

public class SetHours implements State {

	//display incremented time to user
	public void doAction(Time t) {
		// TODO Auto-generated method stub
		System.out.println(this.getClass());
		t.advanceHr();
		System.out.println(t);
	}

	//display time according to button code
	public void doAction(Time t, boolean b) {
		// TODO Auto-generated method stub
		System.out.println(this.getClass());
		if(b)
			t.advanceHr();
		System.out.println(t);
	}

}
