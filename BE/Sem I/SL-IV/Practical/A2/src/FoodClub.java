
public class FoodClub extends Club{

	private String favSweet;
	private String favStarter;
	private String favRestaurant;
	@Override
	public String toString() {
		return "FoodClub [favSweet=" + favSweet + ", favStarter=" + favStarter + ", favRestaurant=" + favRestaurant
				+ ", fee=" + fee + ", validity=" + validity + "]";
	}
	public String getFavSweet() {
		return favSweet;
	}
	public void setFavSweet(String favSweet) {
		this.favSweet = favSweet;
	}
	public String getFavStarter() {
		return favStarter;
	}
	public void setFavStarter(String favStarter) {
		this.favStarter = favStarter;
	}
	public String getFavRestaurant() {
		return favRestaurant;
	}
	public void setFavRestaurant(String favRestaurant) {
		this.favRestaurant = favRestaurant;
	}
	public FoodClub(String favSweet, String favStarter, String favRestaurant) {
		super();
		this.favSweet = favSweet;
		this.favStarter = favStarter;
		this.favRestaurant = favRestaurant;
	}
	public FoodClub() {
		super();
		// TODO Auto-generated constructor stub
	}
	
}
