/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 2
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 *  
 */

package ship;

public class Ship {

	private String name;
	private float size;
	private String destination;
	private float weight;
	private int crewMembers;
	
	public Ship() {}
	public Ship(String name, float size, String destination, float weight, int crewMembers) {
		this.name = name;
		this.size = size;
		this.destination = destination;
		this.weight = weight;
		this.crewMembers = crewMembers;
	}
	protected String getName() {
		return name;
	}
	protected void setName(String name) {
		this.name = name;
	}
	protected float getSize() {
		return size;
	}
	protected void setSize(float size) {
		this.size = size;
	}
	protected String getDestination() {
		return destination;
	}
	protected void setDestination(String destination) {
		this.destination = destination;
	}
	protected float getWeight() {
		return weight;
	}
	protected void setWeight(float weight) {
		this.weight = weight;
	}
	protected int getCrewMembers() {
		return crewMembers;
	}
	protected void setCrewMembers(int crewMembers) {
		this.crewMembers = crewMembers;
	}
	
	// Print method will print properties of Ship Class
	// Will be overridden in child classes
	//String name, float size, String destination, float weight, int crewMembers
	public void print()
	{
		System.out.printf("===SHIP INFO===\nName: %s\nDestination: %s\nSize: %.2f\nWeight: %.2f\nNum of Crew Members: %d\n\n",
				this.name, this.destination, this.size, this.weight, this.crewMembers);
	}
	
	
}
