import java.util.Date;

public class Book {

	private String title;
	private String author;
	private Person issuer;
	private Date issueDate;
	public Book() {
		super();
		// TODO Auto-generated constructor stub
		this.issuer = null;
		this.issueDate = null;
	}

	public Book(String title, String author) {
		super();
		this.title = title;
		this.author = author;
		this.issuer = null;
		this.issueDate = null;
	}

	public String getAuthor() {
		return author;
	}
	
	public Date getIssueDate() {
		return issueDate;
	}

	public Person getIssuer() {
		return issuer;
	}

	public String getTitle() {
		return title;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public void setIssueDate(Date issueDate) {
		this.issueDate = issueDate;
	}

	public void setIssuer(Person issuer) {
		this.issuer = issuer;
	}

	public void setTitle(String title) {
		this.title = title;
	}
	
}
