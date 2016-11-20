
public class Lamp {

	private boolean state;//switch state on or off
	private int level;
	
	public Lamp() {
		super();
		// TODO Auto-generated constructor stub
		state=false;
		level=0;
	}
	
	public boolean getState() {
		return state;
	}


	public int getLevel() {
		return level;
	}

	public void setState(boolean state) {
		if(state==true)
			level=1;
		else
			level=0;
		this.state = state;
	}

	public void dimmer()
	{
		System.out.println("Lamp Switch: "+state);
		System.out.println("Old Intensity Level: "+level);
		if(state==true)
		{
			level=(level%3)+1;
		}
		System.out.println("New Intensity Level: "+level+"\n");
	}
}
