
public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PlacementCall pc=new PlacementCall();

		Candidate c=new Candidate(1,"sam","samkit5495@gmail.com","8600086024",90);
		
		pc.newCandidate(c);
		
		Company co=new Company("Google",999999, "CEO", 80);
		
		pc.newCompany(co);
		
		System.out.println("Eligible Companies for "+c.getName());
		pc.showEligible(c);
		
		System.out.println("Eligible Candidates for "+co.getName());
		pc.showEligible(co);
		
		c.register(co);
		
		System.out.println();
		
		co.selectionLetter();
		
		co.schedule();
		
	}

}
