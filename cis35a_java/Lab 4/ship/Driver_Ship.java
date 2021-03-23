/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 2
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 *  
 *  Ship Driver
 *  
 */

package ship;

public class Driver_Ship {
	public static void main (String[] args)
	{
		Ship[] shipArr = new Ship[5];
		
		//String name, float size, String destination, float weight, int crewMembers
		//int containers, int cranes,String fleet, String itemType, float shippingCost)
		//passengers;
//		private int rooms;
//		private int shows;
//		private int restaurants;
//		private String company; 
		shipArr[0] = new Ship("Queen Mary", 1019, "Long Beach", 18960, 25);
		shipArr[0].print();
		
		shipArr[1] = new CargoShip("NC-2559", 1540, "New York", 20384, 30, 250, 5, "MSC", "Steel & Other Metals", 3500);
		shipArr[1].print();			// Overridden method of print in CargoShip will be called instead of Ship's print()
		
		shipArr[2] = new CruiseShip("SS Tipton", 900, "Norway", 15000, 65, 300, 57, 3, 5, "Blue Inc.");
		shipArr[2].print();        // Overridden method from CruiseShip prints instead of Ships'
		
		shipArr[3] = new Ship("StarLord", 800, "Italy", 10989, 15);
		shipArr[3].print();        // Ship's print method called
		
		shipArr[4] = new CruiseShip("Bangtan", 987, "Mexico", 12241 , 47, 223 , 20 , 2 , 3, "Crown Cruises");
		shipArr[4].print();        // Overridden method from CruiseShip prints instead of Ships'
	}
}
