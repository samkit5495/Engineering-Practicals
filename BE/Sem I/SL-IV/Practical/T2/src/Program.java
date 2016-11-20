import java.util.Scanner;

public class Program {
	
	public static Scanner sc=new Scanner(System.in);

	public static int menu()
	{
		System.out.println("0. Exit");
		System.out.println("1. New Book");
		System.out.println("2. New Issuer");
		System.out.println("3. Issue Book");
		System.out.println("4. Return Book");
		System.out.println("5. Book Available");
		return sc.nextInt();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LibrarySystem ls=new LibrarySystem();
		int ch;
		Book b;
		Person p;
		while((ch=menu())!=0)
		{
			switch(ch)
			{
			case 1:
				b=new Book();
				System.out.print("Enter Title: ");
				b.setTitle(sc.next());
				System.out.print("Enter Author: ");
				b.setAuthor(sc.next());
				ls.newBook(b);
				break;
			case 2:
				p=new Person();
				System.out.print("Enter Name: ");
				p.setName(sc.next());
				System.out.print("Enter Max Issue Book Limit: ");
				p.setMaxBooks(sc.nextInt());
				ls.newIssuer(p);
				break;
			case 3:
				System.out.print("Enter Issuer Name: ");
				p=ls.findIssuer(sc.next());
				System.out.println("Enter Book Title: ");
				b=ls.findBook(sc.next());
				ls.issueBook(p, b);
				break;
			case 4:
				System.out.print("Enter Issuer Name: ");
				p=ls.findIssuer(sc.next());
				System.out.println("Enter Book Title: ");
				b=ls.findBook(sc.next());
				ls.returnBook(p, b);
				break;
			case 5:
				System.out.println("Enter Book Name: ");
				System.out.println(ls.bookAvailable(sc.next()));
				break;
			}
		}
	}

}
