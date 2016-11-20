package com.se.state;

public class TestClient {

	public static void main(String[] args) {
		Document doc1 = new Document("Progress Report",
				"Project progress in the week ending on 2015.06.27...");
		doc1.acquire();;
		doc1.write(false);
		doc1.write(true);
		doc1.review();
		doc1.publish();

		Document doc2 = new Document("Progress Report",
				"Project progress");
		doc2.acquire();;
		doc2.write(false);
		doc2.write(true);
		doc2.review();
		doc2.publish();

	}

}
