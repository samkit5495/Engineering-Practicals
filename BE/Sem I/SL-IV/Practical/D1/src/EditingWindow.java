
import java.util.ArrayList;


public class EditingWindow {

	private ArrayList<Shape> drawList;//composition

	
	public ArrayList<Shape> getDrawList() {
		return drawList;
	}

	public void setDrawList(ArrayList<Shape> drawList) {
		this.drawList = drawList;
	}

	public EditingWindow() {
		super();
		this.drawList = new ArrayList<Shape>();
	}
	
}
