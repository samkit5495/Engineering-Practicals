
public class Program {

	public static void main(String[] args) {
		Lamp lamp=new Lamp();
		lamp.dimmer();
		lamp.setState(true);
		lamp.dimmer();
		lamp.dimmer();
		lamp.dimmer();
		lamp.setState(false);
		lamp.dimmer();
	}

}
