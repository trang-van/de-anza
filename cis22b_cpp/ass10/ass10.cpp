// Assignment #10
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Quadrilateral
{
protected:
    int a, b;       //sides
    string type;
public:
    Quadrilateral(const int&, const int&, const string&);
    virtual ~Quadrilateral() {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    string getType() const
    {
        return type;
    }
    int getSide1() const
    {
        return a;
    }
    int getSide2() const
    {
        return b;
    }
};

class Rectangle: public Quadrilateral
{
public:
    Rectangle(const int&, const int&, const string&);
    virtual double area() const;
    virtual double perimeter() const;
};

class Square: public Rectangle
{
public:
    Square(const int&, const string&);
    virtual double area() const;
    virtual double perimeter() const;
};

class Parallelogram: public Quadrilateral
{
protected:
    int height;         //new data member
public:
    Parallelogram(const int&, const int&, const int&, const string&);
    virtual double area() const;
    virtual double perimeter() const;
};

class Rhombus: public Parallelogram
{
public:
    Rhombus(const int&, const int&, const string&);
    virtual double area() const;
    virtual double perimeter() const;
};

//Function Prototypes
ostream& operator<<(ostream& out, const Quadrilateral& quad);
Quadrilateral* createQuadrilateralFromString(string);

int main()
{
    const string filename = "ass10data.txt";
    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Unable to open " << filename << endl;
        exit(1);
    }
    string buffer;
    Quadrilateral* ptrQuad;

    while (getline(fin,buffer))
    {
       // Process only valid input
        if (buffer.size() > 1)
        {
            ptrQuad = createQuadrilateralFromString(buffer);
            cout << *ptrQuad << endl;
            delete ptrQuad;
        }

    }
    fin.close();
}


//Constructors
Quadrilateral::Quadrilateral(const int& s1, const int& s2, const string& typ)
: a(s1), b(s2), type(typ){}

Rectangle::Rectangle(const int& s1, const int& s2, const string& typ)
: Quadrilateral(s1, s2, typ){}

Square::Square(const int& s1, const string& typ)
: Rectangle (s1, s1, typ){}

Parallelogram:: Parallelogram(const int& s1, const int& s2, const int& h, const string& typ)
: Quadrilateral (s1, s2, typ), height(h){}

Rhombus::Rhombus (const int& s1, const int& h, const string& typ)
: Parallelogram(s1, s1, h, typ){}

// Area & Perimeter Functions
double Rectangle:: area() const
{
    return a * b;
}

double Rectangle:: perimeter()const
{
    return (2*a)+(2*b);
}

double Square::area() const     //Override Quad
{
    return a * a;
}

double Square::perimeter()const    //Override Quad
{
    return 4 * a;
}

double Parallelogram::area() const      //Override Quad
{
    return a * height;
}

double Parallelogram::perimeter() const      //Override Quad
{
    return (2*a)+(2*b);
}

double Rhombus::area() const      //Override Quad
{
    return a * height;
}

double Rhombus::perimeter()const        //same as Square (??)
{
    return 4 * a;
}

//Overloads << to print object
ostream& operator<<(ostream& out, const Quadrilateral& quad)
{
    if (quad.getType() == "rectangle" || quad.getType() == "parallelogram")
    {
        out << quad.getType() << ": " << " sides " << quad.getSide1() << " and " << quad.getSide2() << ' ';
        out << "  area=" << quad.area() << "  perimeter=" << quad.perimeter();
    }
    else if (quad.getType() == "square" || quad.getType() == "rhombus")
    {
        out << quad.getType() << ": " << " side " << quad.getSide1() << ' ';
        out << "  area=" << quad.area() << "  perimeter=" << quad.perimeter();
    }

    return out;
}

// Used to create prompted shape from file
Quadrilateral* createQuadrilateralFromString(string buf)
{
    string typeTem;
    int aTem, bTem, hTem;
    size_t pos, pos2;

    //Get information from file
    pos = buf.find(' ', 0);
    typeTem = buf.substr(0, pos);
    if (typeTem == "rectangle")
    {
        pos2 = buf.find(' ', pos+1);
        aTem = stoi(buf.substr(pos+1, pos2-(pos+1)));
        pos = pos2;
        pos2 = buf.find("/n", pos+1);
        bTem = stoi(buf.substr(pos+1, pos2-(pos+1)));

        Rectangle* rec = new Rectangle(aTem, bTem, typeTem);
        return rec;
    }else if (typeTem == "square")
    {
        pos2 = buf.find(' ', pos+1);
        aTem = stoi(buf.substr(pos+1, pos2-(pos+1)));

        Square* squ = new Square (aTem, typeTem);
        return squ;
    } else if (typeTem == "parallelogram")
    {
        pos2 = buf.find(' ', pos+1);
        aTem = stoi(buf.substr(pos+1, pos2-(pos+1)));
        pos = pos2;
        pos2 = buf.find(' ', pos+1);
        bTem = stoi(buf.substr(pos+1, pos2-(pos+1)));
        pos = pos2;
        pos2 = buf.find(' ', pos+1);
        hTem = stoi(buf.substr(pos+1, pos2-(pos+1)));

        Parallelogram* parallel = new Parallelogram(aTem, bTem, hTem, typeTem);
        return parallel;
    } else if (typeTem == "rhombus")
    {
        pos2 = buf.find(' ', pos+1);
        aTem = stoi(buf.substr(pos+1, pos2-(pos+1)));
        pos =pos2;
        pos2 = buf.find(' ', pos+1);
        hTem = stoi(buf.substr(pos+1, pos2-(pos+1)));

        Rhombus* rhom = new Rhombus(aTem, hTem, typeTem);
        return rhom;
    }
}
