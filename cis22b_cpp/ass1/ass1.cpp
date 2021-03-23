// Assignment 1
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//Function Prototypes
int calcAssignmentPts(int []);
string calcGrade(double&);

int main()
{
    //Part 1 Variables
    const int CLASS_TOTAL = 400;
    int studentID, labPts, midtermPts, finalPts, codelabsPts;
    int assignmentPts[10];
    int assignmentTotal;            //stores total of 10 assignments
    double grandTotal;              //stores total points from all categories
    double percent;                 //stores percentage out of CLASS_TOTAL
    string grade;

    ifstream inFile("ass1data.txt");
    ofstream outFile ("report1.txt");
    ofstream outFile2 ("report2.txt");
    string fileName;

    //Part 2 Variables
    int countA=0, countB=0, countC=0, countD=0, countF=0;
    int maxPts=0;


    while (inFile.fail())
    {
        cout << "Enter file name: ";
        cin >> fileName;
        inFile.open(fileName);
    }

    //Headers Formatting
    outFile << "Stdnt Id " << "Ex " << setfill('-') << setw(9) << " ";
    outFile << "Assignment " << setfill('-') << setw(10) << " ";
    outFile << "Tot " << setfill(' ') << setw(4);
    outFile << " Mi " << setfill(' ') << setw(2);
    outFile << "Fin" << setfill(' ') << setw(3);
    outFile << " CL" << setfill(' ') << setw(2);
    outFile << " Pts" << setfill(' ') << setw(3);
    outFile << " Pct" << setfill(' ') << setw(3);
    outFile << " Gr" << setfill(' ') << setw(2) << endl;

    outFile << setfill('-') << setw(9) << " ";
    outFile << setfill('-') << setw(3) << " ";
    outFile << setfill('-') << setw(30) << " ";
    outFile << setfill('-') << setw(4) << " ";
    outFile << setfill('-') << setw(4) << " ";
    outFile << setfill('-') << setw(4) << " ";
    outFile << setfill('-') << setw(3) << " ";
    outFile << setfill('-') << setw(4) << " ";
    outFile << setfill('-') << setw(4) << " ";
    outFile << setfill('-') << setw(3) << " " << endl;

    //Processed from Input File
    while (inFile)
    {
        inFile >> studentID >> labPts;
        outFile << setfill('0') << setw(8) << studentID << " "<< labPts << " ";
        for (int i=0; i <10; i++)
        {
            inFile >> assignmentPts[i];
            outFile << setfill(' ') << setw(2) << right << assignmentPts[i] << " ";
        }

        inFile >> midtermPts >> finalPts >> codelabsPts;

        assignmentTotal = calcAssignmentPts(assignmentPts);

        if (assignmentTotal > maxPts){
            maxPts = assignmentTotal;
        }

        outFile << setfill(' ') << setw(3)<< right <<assignmentTotal<< " ";
        outFile << setfill(' ') << setw(3)<< right << midtermPts << " ";
        outFile << setfill(' ') << setw(3)<< right << finalPts << " ";
        outFile << setfill(' ') << setw(2) << right << codelabsPts;

        grandTotal = labPts + assignmentTotal + midtermPts + finalPts + codelabsPts;

        percent = (grandTotal/CLASS_TOTAL) * 100;

        outFile << " " << right << grandTotal << " ";
        outFile << setfill(' ') << setw(3)<< right<< round(percent);

        grade = calcGrade(percent);

        outFile << " " << grade << endl;

        //Part 2- Counting Grades
        if (grade == "A" || grade == "A+" || grade == "A-")
        {
            countA++;
        } else if(grade == "B" || grade == "B+" || grade == "B-"){
            countB++;
        } else if(grade == "C" || grade == "C+" || grade == "C-"){
            countC++;
        } else if(grade == "D" || grade == "D+" || grade == "D-"){
            countD++;
        } else if(grade == "F"){
            countF++;
        }
    }

    outFile2 << "Number of A's = " << countA <<endl;
    outFile2 << "Number of B's = " << countB <<endl;
    outFile2 << "Number of C's = " << countC <<endl;
    outFile2 << "Number of D's = " << countD <<endl;
    outFile2 << "Number of F's = " << countF <<endl;
    outFile2 << "\nMaximum Points = "<< maxPts <<endl;

    inFile.close();
    outFile.close();

    return 0;
}

int calcAssignmentPts(int assignmentPts[])
{
    int total = 0;
    int lowest = assignmentPts[0];      //stores lowest assignment points

    for (int i=0; i < 10; i++){
        total += assignmentPts[i];
    }

    for (int i=0; i < 10; i++)
    {
        if (assignmentPts[i] < lowest)
        {
            lowest = assignmentPts[i];
        }
    }
    return (total-lowest);
}

string calcGrade(double& percent){
    string grade;
    if (percent > 97){
        return "A+";
    } else if (percent < 98 && percent > 92){
        return "A";
    } else if (percent < 93 && percent > 89){
        return "A-";
    } else if (percent < 90 && percent > 86){
        return "B+";
    } else if (percent < 87 && percent > 82){
        return "B";
    } else if (percent < 83 && percent > 79){
        return "B-";
    } else if (percent < 80 && percent > 76){
        return "C+";
    } else if (percent < 77 && percent > 72){
        return "C";
    } else if (percent < 73 && percent > 69){
        return "C-";
    } else if (percent < 70 && percent > 66){
        return  "D+";
    } else if (percent < 67 && percent > 62){
        return "D";
    } else if (percent < 63 && percent > 59){
        return "D-";
    } else if (percent < 60){
        return "F";
    }else{
        return "";
    }
}
