
public class Square extends Shape{

	private double length;
	
	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		if(length>=0)
			this.length = length;
	}

	@Override
	double area() {
		// TODO Auto-generated method stub
		return length*length;
	}

	@Override
	double permimeter() {
		// TODO Auto-generated method stub
		return 4*length;
	}

	public Square(double length,Point p) {
		super(p);
		this.length = length;
	}

}
