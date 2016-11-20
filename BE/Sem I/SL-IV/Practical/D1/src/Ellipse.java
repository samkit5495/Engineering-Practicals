
public class Ellipse extends Shape{

	private double majorAxis,minorAxis;
	
	public Ellipse(double majorAxis, double minorAxis,Point p) {
		super(p);
		this.majorAxis = majorAxis;
		this.minorAxis = minorAxis;
	}

	public double getMajorAxis() {
		return majorAxis;
	}

	public void setMajorAxis(double majorAxis) {
		this.majorAxis = majorAxis;
	}

	public double getMinorAxis() {
		return minorAxis;
	}

	public void setMinorAxis(double minorAxis) {
		this.minorAxis = minorAxis;
	}

	@Override
	double area() {
		// TODO Auto-generated method stub
		return 3.14*minorAxis*majorAxis;
	}

	@Override
	double permimeter() {
		// TODO Auto-generated method stub
		double r1=majorAxis/2;
		double r2=minorAxis/2;
		return 2*3.14*Math.sqrt((r1*r1+r2*r2)/2);
	}

}
