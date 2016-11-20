
public class Badge {

	private int id;
	private String name;
	public int getId() {
		return id;
	}
	@Override
	public String toString() {
		return "Badge [id=" + id + ", name=" + name + "]";
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Badge(int id, String name) {
		super();
		this.id = id;
		this.name = name;
	}
	
}
