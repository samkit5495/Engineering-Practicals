public class CreditCardStrategy implements PaymentStrategy {

private String name;

private String ccno;

private String dateOfExp;

public CreditCardStrategy(String nm, String ccNum, String expiryDate){

this.name=nm;

this.ccno=ccNum;

this.dateOfExp=expiryDate;
}

public void pay(int amount) {

System.out.println("******\nAmount is "+amount +"\nPayment done using credit card");
}

}
