package rsa;
import java.util.Scanner;

public class Main {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RSA rsa=new RSA();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Data to Encrypt:");
		String data=sc.nextLine();
		System.out.println("Encypted Data: ");
		String cypher=rsa.encrypt(data);
		System.out.println(cypher);
		System.out.println("Decrypting Data:");
		System.out.println(cypher);
		System.out.println("Decrepted Data:");
		String decrypt=rsa.decrypt(cypher);
		System.out.println(decrypt);
		sc.close();
	}

}
