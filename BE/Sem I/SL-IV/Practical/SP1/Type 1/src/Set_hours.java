
public class Set_hours implements State {

	
	@Override
	public int doAction(int hr,int min) {
		// TODO Auto-generated method stub
		hr=(hr%12)+1;
		System.out.println("Time: "+hr+":"+min);
		return hr;	
	}

	
}
