/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 Pt 1 - Personal Information Class
 * Date Due: 7/13/2018
 * Date Submitted: 7/13/2018
 * 
 * Description:  Prompts user to input name, address, age, phone number.
	 			 Displays information once entered. Program tracks the 
	 			 number of people created.
 * 
 */

public class PersonalInformation {

	private String name;
	private String address;
	private String age;
	private String phoneNum;
	private static int count;

	// Constructors
	PersonalInformation() {
		count++;
	} // default constructor

	public PersonalInformation(String name, String address, String age, String phoneNum) {
		count++;
		this.name = name;
		this.address = address;
		this.age = age;
		this.phoneNum = phoneNum;
	}

	// Getters
	public String getName() {
		return this.name;
	}

	public String getAddress() {
		return this.address;
	}

	public String getAge() {
		return this.age;
	}

	public String getPhoneNum() {
		return this.phoneNum;
	}

	// Setters
	public void setName(String n) {
		this.name = n;
	}

	public void setAddress(String add) {
		this.address = add;
	}

	public void setAge(String ag) {
		this.age = ag;
	}

	public void setPhoneNum(String p) {
		this.phoneNum = p;
	}

	public void print() {
		System.out.printf("\n===Person #%d===\nName: %s\n" + "Address: %s\nAge: %s\nPhone Number: %s\n", count,
				this.name, this.address, this.age, this.phoneNum);
	}
}
