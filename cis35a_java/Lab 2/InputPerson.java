/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 Pt 1 - PersonalInfo Driver
 * Date Due: 7/13/2018
 * Date Submitted: 7/13/2018
 * 
 * Description:  Prompts user to input name, address, age, phone number.
	 			 Displays information once entered. Program tracks the 
	 			 number of people created.
 * 
 */

import java.util.Scanner;

public class InputPerson {

	static Scanner input = new Scanner(System.in);

	public static void inputNewPerson(PersonalInformation a1) {
		System.out.printf("%s", "Enter your name: ");
		String name = input.nextLine();
		a1.setName(name);

		System.out.printf("%s", "Enter your address: ");
		String address = input.nextLine();
		a1.setAddress(address);

		System.out.printf("%s", "Enter your age: ");
		String age = input.nextLine();
		a1.setAge(age);

		System.out.printf("%s", "Enter your phone number: ");
		String phoneNum = input.nextLine();
		a1.setPhoneNum(phoneNum);
	}

	public static void main(String[] args) {

		PersonalInformation p1 = new PersonalInformation();
		inputNewPerson(p1);
		p1.print();
		System.out.println();

		PersonalInformation p2 = new PersonalInformation();
		inputNewPerson(p2);
		p2.print();
		System.out.println();

		PersonalInformation p3 = new PersonalInformation();
		inputNewPerson(p3);
		p3.print();
		System.out.println();
	}

}
