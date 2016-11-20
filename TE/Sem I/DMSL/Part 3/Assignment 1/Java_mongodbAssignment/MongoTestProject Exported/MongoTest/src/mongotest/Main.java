/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package mongotest;

/**
 *
 * @author sai krishna
 */
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.MongoClient;
import com.mongodb.MongoClientOptions;
import com.mongodb.MongoCredential;
import com.mongodb.ServerAddress;
import java.net.UnknownHostException;
import com.mongodb.*;

import java.util.List;
import java.util.Set;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws UnknownHostException{
        // TODO code application logic here
        MongoClient mongoClient = new MongoClient( "localhost" , 27017 );
        DB db = mongoClient.getDB("teacherjava");
        Set<String> colls = db.getCollectionNames();

for (String s : colls) {
    System.out.println(s);
}
String name = "Abhinay";
DBCollection coll = db.getCollection("college");
BasicDBObject doc = new BasicDBObject("Name", name)
        .append("Emp No", "9112")
        .append("Dept", "IT");
        
coll.insert(doc);
//DBCursor myDoc = coll.find();
//System.out.println(myDoc);
System.out.println(coll.getCount());
DBCursor cursor = coll.find();
try {
   while(cursor.hasNext()) {
       System.out.println(cursor.next());
   }
} finally {
   cursor.close();
}
}
    }

