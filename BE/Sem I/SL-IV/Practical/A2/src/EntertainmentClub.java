
public class EntertainmentClub extends Club {

	private String favMusic;
	private String favMovie;
	private String favPlace;
	public String getFavMusic() {
		return favMusic;
	}
	public void setFavMusic(String favMusic) {
		this.favMusic = favMusic;
	}
	public String getFavMovie() {
		return favMovie;
	}
	public EntertainmentClub(String favMusic, String favMovie, String favPlace) {
		super();
		this.favMusic = favMusic;
		this.favMovie = favMovie;
		this.favPlace = favPlace;
	}
	public EntertainmentClub() {
		super();
		// TODO Auto-generated constructor stub
	}
	public void setFavMovie(String favMovie) {
		this.favMovie = favMovie;
	}
	public String getFavPlace() {
		return favPlace;
	}
	public void setFavPlace(String favPlace) {
		this.favPlace = favPlace;
	}
	@Override
	public String toString() {
		return "EntertainmentClub [favMusic=" + favMusic + ", favMovie=" + favMovie + ", favPlace=" + favPlace
				+ ", fee=" + fee + ", validity=" + validity + "]";
	}
}
