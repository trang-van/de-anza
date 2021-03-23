
/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 2
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 * 
 * Detail: Extension of Ship Class
 * 
 */

package ship;

public class CruiseShip extends Ship {

	private int passengers;
	private int rooms;
	private int shows;
	private int restaurants;
	private String company; 
	
	public CruiseShip() {}
	public CruiseShip(String name, float size, String destination, float weight, int crewMembers,int passengers, int rooms, int shows, int restaurants, String company) {
		super(name, size, destination, weight, crewMembers);
		this.passengers = passengers;
		this.rooms = rooms;
		this.shows = shows;
		this.restaurants = restaurants;
		this.company = company;
	}
	
	protected int getPassengers() {
		return passengers;
	}
	protected void setPassengers(int passengers) {
		this.passengers = passengers;
	}
	protected int getRooms() {
		return rooms;
	}
	protected void setRooms(int rooms) {
		this.rooms = rooms;
	}
	protected int getShows() {
		return shows;
	}
	protected void setShows(int shows) {
		this.shows = shows;
	}
	protected int getRestaurants() {
		return restaurants;
	}
	protected void setRestaurants(int restaurants) {
		this.restaurants = restaurants;
	}
	protected String getCompany() {
		return company;
	}
	protected void setCompany(String company) {
		this.company = company;
	}
	
	// Override Print
	public void print()
	{
		System.out.printf("===CRUISE SHIP INFO===\nName: %s\nCompany: %s\nDestination: %s\nSize: %.2f\nWeight: %.2f\nNum of Crew Members: %d\n\n"
				+ "Num of Passengers: %d\nNum of Rooms: %d\nNum of Restaurants: %d\n\n",
				this.getName(),this.company, this.getDestination(), this.getSize(), this.getWeight(), this.getCrewMembers(), this.passengers, 
				this.rooms,this.restaurants);
	}
	

}
