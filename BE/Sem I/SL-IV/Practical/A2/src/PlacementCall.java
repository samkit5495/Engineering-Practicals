import java.util.ArrayList;

public class PlacementCall {

	private ArrayList<Candidate> candidList;
	private ArrayList<Company> companyList;
	public PlacementCall() {
		super();
		// TODO Auto-generated constructor stub
		candidList=new ArrayList<>();
		companyList=new ArrayList<>();
	}
	
	public void newCandidate(Candidate c)
	{
		candidList.add(c);
	}
	
	public void newCompany(Company c)
	{
		companyList.add(c);
	}

	public ArrayList<Candidate> getCandidList() {
		return candidList;
	}

	public ArrayList<Company> getCompanyList() {
		return companyList;
	}
	
	public void showEligible(Company co)
	{
		for(Candidate c:candidList)
		{
			if(c.getAggregate()>=co.getCriteria())
				System.out.println(c);
		}
	}
	
	public void showEligible(Candidate c)
	{
		for(Company co:companyList)
		{
			if(c.getAggregate()>=co.getCriteria())
				System.out.println(co);
		}
	}
}
