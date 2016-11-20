
public class Program {

	public static void main(String args[])
	{
		EditingWindow ew=new EditingWindow();
		
		Shape a=new Square(5,new Point(2,2));
		Shape b=new Rect(3, 5, new Point(2,2));
		DrawingEditor.draw(ew, a);
		DrawingEditor.draw(ew, b);
		System.out.println(a.area());
		System.out.println(b.area());
		System.out.println(DrawingEditor.total_area(ew));
		System.out.println();
		System.out.println(a.permimeter());
		System.out.println(b.permimeter());
		System.out.println(DrawingEditor.total_permimeter(ew));
	}
}
