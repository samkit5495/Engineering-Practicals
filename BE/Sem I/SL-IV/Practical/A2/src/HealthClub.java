
public class HealthClub extends Club {

	private int heigth;
	private int weight;
	public HealthClub(int heigth, int weight) {
		super();
		this.heigth = heigth;
		this.weight = weight;
	}
	public int getHeigth() {
		return heigth;
	}
	@Override
	public String toString() {
		return "HealthClub [heigth=" + heigth + ", weight=" + weight + ", fee=" + fee + ", validity=" + validity + "]";
	}
	public HealthClub() {
		super();
		// TODO Auto-generated constructor stub
	}
	public void setHeigth(int heigth) {
		this.heigth = heigth;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
}
