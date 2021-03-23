  // Assignment #7
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

//Constants and Global Variables
const string Months[13] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
const int CurrentYear = 2018;

int DaysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
    int* month;
    int* day;
    int* year;

    void parseString(string, char);

    public:
        Date();
        Date(const Date &);          //Copy Constructor
        Date(int, int, int = CurrentYear%100);
        Date(string);
        Date(int);
        ~Date();                    //Destructor Prototype

        //Functions

        void print()const;
        void print_long()const;
};

int main()
{
    Date today;
    Date todayCopy(today);
    Date feb2815(2,28,15);            // assume the year is 2015
    Date assignmentDueDate(3,6);      // assume the year is the Current Year
    Date feb2895("02-28-95");         // assume the year is 1995
    Date newYearsDay("01/01/18");     // assume the year is 2018
    Date idesOfMarch(74);             // assume the year is the Current Year
    Date eoy(365);                    // assume the year is the Current Year

    cout << "Today: "; today.print();
    cout << "Today: "; todayCopy.print();
    cout << "feb2815: "; feb2815.print();
    cout << "Assignment due date: "; assignmentDueDate.print();
    cout << "feb2895: "; feb2895.print();
    cout << "New Years Day: "; newYearsDay.print();
    cout << "Ides of March: "; idesOfMarch.print();
    cout << "Last Day of Year: "; eoy.print();

    cout << "Today: "; today.print_long();
    cout << "Today: "; todayCopy.print_long();
    cout << "feb2815: "; feb2815.print_long();
    cout << "Assignment due date: "; assignmentDueDate.print_long();
    cout << "feb2895: "; feb2895.print_long();
    cout << "New Years Day: "; newYearsDay.print_long();
    cout << "Ides of March: "; idesOfMarch.print_long();
    cout << "Last Day of Year: "; eoy.print_long();
}

// Current Date Constructor
Date::Date()
{
    time_t now = time(0);
    tm* ptr = localtime(&now);
    month = new int(ptr->tm_mon + 1);
    day = new int(ptr->tm_mday);
    year = new int(ptr->tm_year + 1900);
}

//Copy Constructor
Date::Date(const Date &obj): month(new int(*(obj.month))), day(new int(*(obj.day))), year(new int (*(obj.year))){}

//3 Parameter Constructor- Month, Day, Year
Date::Date(int m, int d, int y): month(new int(m)), day(new int(d)), year(new int(y)){}

// Function to Parse String for String Parameter Constructor
void Date::parseString(string str, char sym)
{
    size_t pos, pos2, pos3;

    pos = str.find(sym, 0);
    month = new int(stoi(str.substr(0, pos)));

    pos2 = str.find(sym, pos+1);
    day = new int(stoi(str.substr(pos+1, pos2-(pos+1))));
    pos = pos2;

    pos3 = str.find(sym, pos+1);
    year = new int (stoi(str.substr(pos+1, pos3-(pos+1))));
}

 // String Parameter Constructor
Date::Date(string str)
{
    int pos;

    pos = str.find("-",0);

    if (pos < 0)
    {
        parseString(str, '/');
    }
    else
    {
        parseString(str, '-');
    }
}

// Days From New Year Day Constructor
Date::Date(int daysIn)
{
    int sum =0;
    for(int i=1; i < 13; i++)
    {
        if(sum <= daysIn)
        {
            sum += DaysPerMonth[i];
            month = new int(i);
            day = new int(daysIn-(sum-DaysPerMonth[i]));
            year= new int (CurrentYear);
        }
    }
}

//Destructor
Date::~Date()
{
    delete month;
    delete day;
    delete year;

    month = nullptr;
    day = nullptr;
    year = nullptr;
}

// Prints the Date MM/DD/YY
void Date::print() const
{
    cout << right << setw(2)<< setfill('0') << *month << '/';
    cout << right << setw(2)<< setfill('0')<< *day << '/';
    cout << *year % 100 << endl;
}

// Prints the Date Written Out
void Date::print_long()const
{
    if (*year == CurrentYear)
    {
        cout << Months[*month] << ' ' << *day << ", " << CurrentYear << endl;
    }
    else if (*year%100 < 50)
    {
        cout << Months[*month] << ' ' << *day << ", " << 2000 + *year%100 << endl;
    }
    else if (*year%100 >= 50)
    {
        cout << Months[*month] << ' ' << *day << ", " << 1900 + *year%100 << endl;
    }
}

