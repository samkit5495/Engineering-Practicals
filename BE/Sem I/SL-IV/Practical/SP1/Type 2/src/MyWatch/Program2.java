package MyWatch;
import Watch.*;

public class Program2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DigitalWatch d=new DigitalWatch();
		d.doAction();
		d.setState(new SetHours());
		d.doAction();
		d.setState(new SetMinutes());
		d.doAction();
		d.setState(new DisplayTime());
		d.doAction();
	}

}
