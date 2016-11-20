
public class CopyMachine {

	private State state;
	private int count=0;
	private String size;
	public CopyMachine() {
		super();
		// TODO Auto-generated constructor stub
		state=State.OFF;
	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}
	
	public void onMachine()
	{
		System.out.println("Previous State: "+state);
		if(state==State.OFF)
		{
			setState(State.warming);
			System.out.println("Machine Turned ON\nReady Light Turned ON");
			initialCheck();
		}
		else
			System.out.println("Machine is already ON");
		
	}
	
	public void initialCheck()
	{
		if(state==State.warming)
		{
			do
			{
				System.out.println("State: "+state);
				System.out.println("Ready light is flashing");
				System.out.println("Initial check:\n1. Completed or\n2. Not: ");
				
			}while(Program.sc.nextInt()!=1);
			System.out.println("Initial Check finished!!!");
			setState(State.ready);
			System.out.println("State: "+state);
			count=1;
			size="Normal";
			System.out.println("No of copies Set 1 & Size = Normal");
		}
		else
			System.out.println("Not in warming state!!!");
	}
	
	public void changeSize(String size)
	{
		this.size=size;
	}
	
	public void changeCount(int count)
	{
		this.count=count;
	}
	
	public void change()
	{
		if(state==State.ready)
		{
			do
			{
				int o;
				System.out.println("Ready light turned on");
				do
				{
					System.out.println("0. Start Copying");
					System.out.println("1. Change Count");
					System.out.println("2. Change Size");
					o=Program.sc.nextInt();
					if(o==1)
					{
						System.out.println("Enter Count: ");
						changeCount(Program.sc.nextInt());				
					}
					else if(o==2)
					{
						System.out.println("Enter Size: ");
						changeSize(Program.sc.next());
					}
				}while(o!=0);
				startButton();
				System.out.println("1. Continue Ready State\n2. Turn OFF");
			}
			while(Program.sc.nextInt()!=2);
			setState(State.OFF);
			System.out.println("Machine turned OFF");
		}
		else
			System.out.println("Not in Ready State");
	}
	
	public void startButton()
	{
		System.out.println("Previous State: "+state);
		if(state==State.ready)
		{
			setState(State.copying);
			System.out.println("State: "+state);
			System.out.println("Copying Started");
			while(count!=0)
			{
				System.out.println("Printing copy no "+count+" of size "+size+".");
				count--;
			}
			setState(State.ready);
			System.out.println("State: "+state);
		}
		else
			System.out.println("Machine is not ready");
	}
}
