
public class Circle extends Shape{
	private double radius;
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	@Override
	double area() {
		// TODO Auto-generated method stub
		return 3.14*radius*radius;
	}

	@Override
	double permimeter() {
		// TODO Auto-generated method stub
		return 2*3.14*radius;
	}

	public Circle(double radius,Point p) {
		super(p);
		this.radius = radius;
	}

}
