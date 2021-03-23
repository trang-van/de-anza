// Assignment #8
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char* input;
    static int numofA;
public:
    String(const char*);
    String(const String&);
    String();
    ~String();
    static int a_count();
    friend ostream& operator<< (ostream&, const String&);
    bool operator< (const String&) const;
    bool operator== (const String&) const;
    String operator= (const String&);
    int operator!();
    const char* operator*() const;
    String operator+ (const String& b);
    void operator +=(const String& c);
    char &operator[](int val);
};

// Initializing Static Data Member
int numOfA =0;

//Default Constructor
String::String():input(new char[1])
{
    strcpy(input, "");
}

// Constructor Initializer
String::String(const char* buf): input(new char[strlen(buf)+1])
{
    strcpy(input, buf);

    //Counting Number of 'a' in each C-string
    for (unsigned int i=0; i < strlen(buf); i++)
    {
        if (buf[i]=='a')
        {
            numOfA++;
        }
    }
}

//Copy Constructor
String::String (const String& obj): input(new char[strlen(obj.input)+1])
{
    strcpy(input, obj.input);

    //Counting Number of 'a' in each C-string Copy
    for (unsigned int i=0; i < strlen(obj.input); i++)
    {
        if (obj.input[i]=='a')
        {
            numOfA++;
        }
    }
}

//Static Member Function to Count 'a'
int String::a_count()
{
    return numOfA;
}

//Overloaded Insertion Operator
ostream& operator<< (ostream& out, const String& obj)
{
	out << obj.input;
	return out;
}

//Overloaded Relational Operator
bool String::operator< (const String& b) const
{
    bool flag = 1;
    if(input < b.input)
    {
        return flag;
    }
    return 0;
}

bool String::operator== (const String& b) const
{
    bool flag = 1;
    if(input == b.input)
    {
        return flag;
    }
    return 0;
}

//Overloaded Assignment Operator
String String::operator= (const String& b)
{
    //Take Away Number of 'a' in original C-string
    for (unsigned int i=0; i < strlen(input); i++)
    {
        if (input[i]=='a')
        {
            numOfA--;
        }
    }

    input = b.input;

    for (unsigned int i=0; i < strlen(b.input); i++)
    {
        if (b.input[i]=='a')
        {
            numOfA++;
        }
    }

    return input;
}

//Overloaded Bang (!) Operator to Get Size of C-strings
int String::operator!()
{
    if (input) return strlen(input);
    return 0;
}

//Overloaded Unary (*) Operator to
const char* String::operator*() const
{
    return input;
}

// Overloaded + operator to join 2 c-strings
String String::operator+ (const String& b)
{
    char* temp = new char[strlen(input)+1];
    strcpy(temp, input);
    strcat(temp, b.input);
    return temp;
}

//Overloaded += to Add C to A
void String::operator +=(const String& c)
{
    char* temp = new char[strlen(input)+strlen(c.input)+1];
    strcpy(temp, input);
    strcat(temp, c.input);

    for (unsigned int i=0; i < strlen(c.input); i++)
    {
        if (c.input[i]=='a')
        {
            numOfA++;
        }
    }

    delete[]input;
    input = temp;
}

//Overloaded Index[]
char &String::operator[](int val)
{
    return input[val];
}

//Destructor
String::~String()
{
    for (unsigned int i=0; i < strlen(input); i++)
    {
        if (input[i]=='a')
        {
            numOfA--;
        }
    }

    delete [] input;
    input = nullptr;
}

int main()
{
    // Constructors
    String A("apple");
    String B("banana");
    String C("cantaloupe");
    String D(B);
    String E;

    // static member function
    cout << "Number of a's = " << String::a_count() << endl << endl;

    // Overloaded insertion operator
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "E = " << E << endl << endl;

    // Relational operators
    cout << boolalpha;
    cout << "A < B " << (A < B) << endl;
    cout << "B < A " << (B < A) << endl;
    cout << "A == B " << (A == B) << endl << endl;

    // Assignment operator
    A = B;
    cout << "A = " << A << endl;
    cout << "A == B " << (A == B) << endl << endl;

    // Size (bang) operator
    cout << "A size = " << !A << endl;
    cout << "E size = " << !E << endl << endl;

    // Unary * operator
    cout << "C text = " << *C << endl << endl;

   // Plus operator
    cout << "A + B = " << A + B << endl << endl;

    // Plus equal operator
    A += C;
    cout << "A = " << A << endl << endl;

   // Index operator
    cout << "A[3] = " << A[3] << endl << endl;

    // static member function
    cout << "Number of a's = " << String::a_count() << endl;
}
