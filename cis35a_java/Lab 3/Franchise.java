/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 - Franchise
 * Date Due: 7/18/2018
 * Date Submitted: 7/18/2018
 * 				
 */

public class Franchise {
	private Store stores[];
	
	public Franchise(int num) {
			stores = new Store[num];
	}

	public Store getStores(int i) {
		return stores[i];
	}

	public void setStores(Store stores, int i) {
		this.stores[i] = stores;
	}
	public int numberofstores()
	{
		return stores.length;
	}
	
}
