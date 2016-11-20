
public class DrawingEditor {

	static public void draw(EditingWindow ew/*need of this object for class*/,Shape s)//i.e dependency windoweditor ka object pass kiya he drawingeditor me.
	{
		ew.getDrawList().add(s);
	}
	static public double total_area(EditingWindow ew)
	{
		double t=0;
		for(Shape s:ew.getDrawList())
		{
			t+=s.area();
		}
		return t;
	}
	static public double total_permimeter(EditingWindow ew)
	{
		double t=0;
		for(Shape s:ew.getDrawList())
		{
			t+=s.permimeter();
		}
		return t;
	}
}
