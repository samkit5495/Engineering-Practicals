
public class Program {

	public static void main(String[] args) {
		
		Digital_Watch dw=new Digital_Watch(11,12);
		//display time
		dw.doAction();
		State s=new Set_hours();
		dw.setState(s);
		dw.doAction();
		s=new Set_Minutes();
		dw.setState(s);
		dw.doAction();
	}
}
