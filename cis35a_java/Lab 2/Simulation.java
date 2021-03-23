/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 Pt 1 - Coin Toss Simulation
 * Date Due: 7/13/2018
 * Date Submitted: 7/13/2018
 * 
 * Description: Associates with Coin class to toss a Coin object 20 times.
 * 				Keeps track of how many heads or tails was flipped. 
 * 				
 */
public class Simulation {
	
	public void toss(Coin c)
	{
		int headCt =0;
		int tailCt =0;
		for (int i = 0; i < 20; i++)
		{
			c.toss();
			if (c.getSideUp() == "heads")
			{
				headCt++;
			} else if (c.getSideUp() == "tails")
			{
				tailCt++;
			}
			
			System.out.printf("SIDE: %s\n", c.getSideUp());
		}
		
		System.out.printf("\n\nHeads: %d", headCt);
		System.out.printf("\nTails: %d", tailCt);

	}

}
