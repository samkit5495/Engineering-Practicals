package MyWatch;
import Watch.*;

public class Program1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DigitalWatch d=new DigitalWatch();
		d.doAction();
		d.doAction(new SetHours());
		d.doAction(new SetMinutes());
		d.doAction(new DisplayTime());
		
	}

}
