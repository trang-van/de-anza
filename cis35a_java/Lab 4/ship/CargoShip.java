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

public class CargoShip extends Ship {

	private int containers;
	private int cranes;
	private String fleet;	
	private String itemType;
	private float shippingCost;
	
	public CargoShip() {}
	public CargoShip (String name, float size, String destination, 
			float weight, int crewMembers,int containers, int cranes, 
			String fleet, String itemType, float shippingCost)
	{	
		super(name, size, destination, weight, crewMembers);
		this.containers = containers;
		this.cranes = cranes;
		this.fleet = fleet;
		this.itemType = itemType;
		this.shippingCost = shippingCost;
	}
	
	protected int getContainers() {
		return containers;
	}
	protected void setContainers(int containers) {
		this.containers = containers;
	}
	protected int getCranes() {
		return cranes;
	}
	protected void setCranes(int cranes) {
		this.cranes = cranes;
	}
	protected String getFleet() {
		return fleet;
	}
	protected void setFleet(String fleet) {
		this.fleet = fleet;
	}
	protected String getItemType() {
		return itemType;
	}
	protected void setItemType(String itemType) {
		this.itemType = itemType;
	}
	protected float getShippingCost() {
		return shippingCost;
	}
	protected void setShippingCost(float shippingCost) {
		this.shippingCost = shippingCost;
	}
	
	//Override Print
	public void print()
	{
		System.out.printf("===CARGO SHIP INFO===\nName: %s\nFleet: %s\nDestination: %s\nSize: %.2f\nWeight: %.2f\nNum of Crew Members: %d\n\n"
				+ "Cargo Type: %s\nNum of Containers: %d\nShipping Cost: %.2f\n\n",
				this.getName(),this.fleet, this.getDestination(), this.getSize(), this.getWeight(), this.getCrewMembers(), this.itemType, 
				this.containers,this.shippingCost);
	}
	
}