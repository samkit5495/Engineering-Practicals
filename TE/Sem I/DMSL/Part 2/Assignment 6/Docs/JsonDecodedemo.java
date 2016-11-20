import java.util.Iterator;
import java.util.Set;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class JsonDecodedemo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		JSONParser parser=new JSONParser();

		//{"student":{"marks":[{"DBMS":"60"},{"TOC":"50"},{"CNT":"65"}],"classname":"TE","name":"XYZ"}}
		String jsonString="{\"student\":{\"marks\":[{\"DBMS\":\"60\"},{\"TOC\":\"50\"},{\"CNT\":\"65\"}],\"classname\":\"TE\",\"name\":\"XYZ\"}}";

		try{
			JSONObject mainobj = (JSONObject)parser.parse(jsonString);

			JSONObject student =(JSONObject)mainobj.get("student");

			System.out.println("Name - "+student.get("name"));
			System.out.println("Classname - "+student.get("classname"));

			JSONArray marks=(JSONArray)student.get("marks");
			for(int i=0;i<marks.size();i++){
				JSONObject subMark =(JSONObject)marks.get(i);

				Set keys=subMark.keySet();
				Iterator keysItr=keys.iterator();
				while(keysItr.hasNext()){
					Object key=keysItr.next();
					System.out.println(key+" - "+subMark.get(key));
				}
			}


		}
		catch(ParseException pe){
			System.out.println(pe);
		}

	}

}
