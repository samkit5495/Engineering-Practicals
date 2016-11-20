
public class Display_time implements State {

	
	@Override
	public int doAction(int hr,int min) {
		// TODO Auto-generated method stub
		System.out.println("Time: "+hr+":"+min);
		return 0;
	}

}
