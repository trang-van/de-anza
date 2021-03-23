
/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 Pt 1 - Coin Class
 * Date Due: 7/13/2018
 * Date Submitted: 7/13/2018
 * 
 * Description: Coin class to generate a random int that corresponds with heads or tails
 * 				
 */

import java.util.Random;

public class Coin {

	private String sideUp;

	public Coin() {
		toss();
	}

	public void toss() {
		Random rand = new Random();
		int flip = rand.nextInt(2) + 1;
		
		if (flip == 1) {
			this.sideUp = "heads";
		} else if (flip == 2) {
			this.sideUp = "tails";
		}

	}

	public String getSideUp() {
		return this.sideUp;
	}

}
