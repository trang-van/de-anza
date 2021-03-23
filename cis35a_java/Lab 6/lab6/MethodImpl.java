package lab6;

import adapter.Studentdata;
import java.io.*;

public abstract class MethodImpl implements Serializable, Studentdata {
	
	private static final long serialVersionUID = 1L;

	public MethodImpl() {
		// Call the method that reads the data from text file into Student []
		Student lab2 [] = new Student[40];
				
		lab2 = Util.readFile("C:\\Users\\Trang\\eclipse-java-workspace\\Assignment 6\\studentData.txt", lab2);
		int studCt = Util.studentCt;
		
		// Compute stats
		Statistics statlab2 = new Statistics();

		statlab2.findlow(lab2, studCt);
		statlab2.findhigh(lab2, studCt);
		statlab2.findavg(lab2, studCt);
		
		// Create an array of StudentStat class. (if there are 15 students then the
		// array size will be 15 as well.
		
		StudentStat ss[] = new StudentStat[studCt];
		
		// Write each StudentStat object to disk.
		for (int i = 0; i < studCt; i++)
		{
			ss[i] = new StudentStat();
			ss[i].setS1(lab2[i]);
			ss[i].setStat(statlab2);
			Student stud = ss[i].getS1();
			Statistics calculatedStats = ss[i].getStat();
			
			int tempId = stud.getSID();
			String id = Integer.toString(tempId);
			
			writeStudstat(stud,calculatedStats, id);
		}
	}

	public void writeStudstat(Student stud, Statistics stat, String studentid) {
		// This method will serialize the one instance of StudentStat to disk.
		 try {
			FileOutputStream a1 = new FileOutputStream(studentid + ".ser");
			ObjectOutputStream s1 = new ObjectOutputStream(a1);
			StudentStat app = new StudentStat();
			if (DEBUG) {
				app.setS1(stud);
				app.setStat(stat);
				s1.writeObject(app);
				System.out.println(studentid + ".ser has been written.\n");
				s1.close();
			}	
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public StudentStat readStudentstat(String studentid) {
		// Should read the contents of serialized file.
		StudentStat B = null;
		try {
			FileInputStream a2 = new FileInputStream(studentid + ".ser");
			ObjectInputStream s2 = new ObjectInputStream(a2);
			if(DEBUG)
			{
				B = (StudentStat)s2.readObject();
				System.out.println("\n\n" + studentid + ".ser has been read.");
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e)
		{
			e.printStackTrace();
		}  catch (ClassNotFoundException e)
		{
			e.printStackTrace();

		}
		return B;
	}
	
	// Implement the methods in Studentdata below.

	public void statistics() {
		// Sets stats in each Studentdata object, writes stats in each obj
		Student lab2 [] = new Student[40];
		
		lab2 = Util.readFile("C:\\Users\\Trang\\eclipse-java-workspace\\Assignment 6\\studentData.txt", lab2);
		int studCt = Util.studentCt;
		
		// Compute stats
		Statistics statlab2 = new Statistics();

		statlab2.findlow(lab2, studCt);
		statlab2.findhigh(lab2, studCt);
		statlab2.findavg(lab2, studCt);
		StudentStat studStat = new StudentStat();		

		studStat.setStat(statlab2);
		studStat.print();
	}

	

	public void printscores(int studentid) {
		// read the object from disk - by calling readStudentstat()
		// and the the print student scores only.
		String id = String.valueOf(studentid);
		StudentStat B = readStudentstat(id);		
		System.out.printf("Student %d's Scores:\n", B.getS1().getSID());

		for (int  i=0;  i <B.getS1().getScores().length ; i++)
		{
			System.out.print(B.getS1().getScores()[i] + " ");
		}
	}
}
