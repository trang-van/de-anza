//Assignments #3
//Trang Van
//Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>


using namespace std;

//Constants
const int numberOfStudents = 50;
const int COLS = 20;
const string filename = "ass1data.txt";

//Function Prototypes (REMEMBER TO MOVE MAIN BACK UP)
void getFile (const string&, int[][COLS]);
int assignmentTotal (int []);
char calcGrade (int);
char getPlusMinus (int );
void sortByCol(int[][COLS], int, char);
void swapRow(int[], int []);                     //Used By sortByCol
void swap(int&, int&);                          //Used by swapRow
void printArray(int [][COLS]);

ofstream outFile;                               // Declared to print reports

int main()
{
    int studentData[numberOfStudents][COLS];
    int total=0;        //stores grand total
    int percent;        //store calculated percent from total

    getFile(filename, studentData);

    for (int i = 0; i < numberOfStudents; i++)
    {
        studentData[i][15] = assignmentTotal(studentData[i]);
        total = studentData[i][1]+ studentData[i][12]+ studentData[i][13] + studentData[i][14] + studentData[i][15];
        studentData[i][16] = total;
        percent = (total/400.0)*100.0;
        studentData[i][17] = percent;
        studentData[i][18] = calcGrade(percent);
        studentData[i][19] = getPlusMinus(percent);
    }

    // Sort & Print First Report By Student ID
    sortByCol(studentData, 0, 'a');
    outFile.open("reportByID.txt");
    printArray(studentData);
    outFile.close();

    // Sort & Print Second Report By Total Points
    outFile.open("reportByTotal.txt");
    sortByCol(studentData, 16, 'd');
    printArray(studentData);
    outFile.close();

    return 0;
}

// Read into file to store in array
void getFile (const string& filename, int data[][COLS])
{
    ifstream inFile (filename);

    if (inFile.fail())
    {
        cout << "Error! File not found." << endl;
        exit(1);
    }

    for (int r = 0; r < numberOfStudents; r++)
    {
        for (int c = 0; c < 15; c++)
        {
            inFile >> data[r][c];
        }
    }

    inFile.close();
}

//Calculate Minimum Assignment Point
int minAssignmentPt (int row[])
{
    int min = row[2];
    for (int i = 3; i <=11; i++)
    {
        if (row[i] < min)
        {
            min = row[i];
        }
    }
    return min;
}

//Calculate Total Assignment Points
int assignmentTotal (int row[])
{
    int total = 0;
    for (int i = 2; i <= 11; i++)
    {
        total += row[i];
    }
    return (total - minAssignmentPt(row));
}


//Calculate Grades Based on Percent from main()
char calcGrade (int percent)
{
    switch (percent/10)
    {
        case 10:
        case 9:  return 'A';
                 break;
        case 8:  return 'B';
                 break;
        case 7:  return 'C';
                 break;
        case 6:  return 'D';
                 break;
        default: ;
    }

    return 'F';
}

//Get + or - for grades from percent from main()
char getPlusMinus (int percent)
{
    if (percent > 97)
    {
        return '+';
    }else if (percent > 59)
    {
        if (percent % 10 > 7)
        {
            return '+';
        } else if (percent % 10 < 2)
        {
            return '-';
        }
    }
    return ' ';
}

//Sort Data by Columns in Ascending & Descending Order
void sortByCol(int a[][COLS], int col, char aOrd)
{
    if (aOrd == 'a')        //ascending order
    {
        int i, j;
        for (i = 0; i < numberOfStudents - 1; i++) {
            for (j = i+1; j < numberOfStudents; j++) {
                if (a[i][col] > a[j][col]) swapRow(a[i],a[j]);
            }
        }
    } else if (aOrd == 'd')     //descending order
    {
        int i, j;
        for (i = 0; i < numberOfStudents - 1; i++) {
            for (j = i+1; j < numberOfStudents; j++) {
                if (a[i][col] < a[j][col]) swapRow(a[i],a[j]);
            }
        }
    }
}

void swapRow(int a[], int b[])
{
    for (int i = 0; i < COLS; i++)
    {
        swap(a[i],b[i]);
    }
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//Prints report
void printArray(int data[][COLS])
{
    outFile << "Stdnt Id  Ex  ------- Assignments ------  Mi  Fin   CL  Tot  Pts  Pct  Gr" << endl;
    outFile << "--------  --  --------------------------  --  ---   --  ---  ---  ---  --" << endl;

    for (int i=0; i < numberOfStudents; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (j == 0)
            {
                outFile << setw(8) << data[i][j] << "  ";
            } else if (j == 1)
            {
                outFile << setw(2) << data[i][j] <<"  ";
            } else if (j > 2 && j <=11)
            {
                outFile << setw(2) << data[i][j] << " ";
            } else if (j == 12 || j==13 || j==14)
            {
                outFile << " ";
                outFile << right << setw(2) << data[i][j]<< "  ";
            } else if (j == 15)
            {
                outFile << setw(3) << data[i][j] << "  ";
            } else if (j == 16)
            {
                outFile << setw(3) << data[i][j] << "  ";
            } else if (j == 17)
            {
                outFile << right << setw(3) << data[i][j] << "  ";
            } else if (j ==18)
            {
                outFile << static_cast<char>(data[i][j]);
            } else if (j ==19)
            {
                outFile << static_cast<char>(data[i][j]);
            }
        }
       outFile << endl;
    }
}
