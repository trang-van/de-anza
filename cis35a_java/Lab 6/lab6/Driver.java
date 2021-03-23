/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 6 - Driver
 * Date Due: 08/07/2018
 * Date Submitted: 08/05/2018
 * 
 */

package lab6;

import adapter.Studentdata;

public class Driver extends MethodImpl {

	private static final long serialVersionUID = 1L;
	public Driver() { 
		super();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Studentdata test = new Driver(); 
		test.statistics();
		test.printscores(1234); 
		test.printscores(8026); 
		test.printscores(1947); 
		test.printscores(2134); 
		test.printscores(6999); 


		
	}

}
