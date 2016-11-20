
public class Rect extends Shape{

	private double length,breadth;
	
	public Rect(double length, double breadth,Point p) {
		super(p);
		this.length = length;
		this.breadth = breadth;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getBreadth() {
		return breadth;
	}

	public void setBreadth(double breadth) {
		this.breadth = breadth;
	}

	@Override
	double area() {
		// TODO Auto-generated method stub
		return length*breadth;
	}

	@Override
	double permimeter() {
		// TODO Auto-generated method stub
		return 2*length+2*breadth;
	}

}
