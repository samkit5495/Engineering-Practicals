
public abstract class Shape {
	
	protected Point centerPoint;//association
	abstract double area();
	abstract double permimeter();
	public Shape(Point centerPoint) {
		super();
		this.centerPoint = centerPoint;
	}
	
}
