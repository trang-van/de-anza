#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book():title(""), author(""), price(0.0), isbn(0){};

Book::Book(string t, string a, double p, unsigned i) {
    title = t;
    author = a;
    price = p;
    isbn = i;
}

/**Access Functions*/

string Book::get_title() const {
    return title;
}

string Book::get_author() const {
    return author;
}

unsigned Book::get_isbn() const {
    return isbn;
}

double Book::get_price() const {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/


bool Book::operator==(const Book& book) {
    return (title == book.title && author==book.author);
}

bool Book::operator<(const Book& book) {
    if (this->title.compare(book.title) == 0 && this->author.compare(book.author) == 0
        && this->price == book.price && this->isbn == book.isbn) {
        return false;
    } else {
        if (this->title.compare(book.title) < 0) {
            return true;
        } else if (this->title.compare(book.title) > 0) {
            return false;
        } else {
            if (this->author.compare(book.author) < 0 ) {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Book::operator>(const Book& book) {
    if (this->title.compare(book.title) == 0 && this->author.compare(book.author) == 0
        && this->price == book.price && this->isbn == book.isbn) {
        return false;
    } else {
        if (this->title.compare(book.title) > 0) {
            return true;
        } else if (this->title.compare(book.title) < 0) {
            return false;
        } else {
            if (this->author.compare(book.author) > 0 ) {
                return true;
            } else {
                return false;
            }
        }
    }
}

// overloading the insertion operator to recognize an ostream object
ostream& operator<<(ostream& os, const Book& book) {
    os << book.title <<" by " << book.author <<"\n";
    os <<"$" <<setprecision(2) <<fixed <<book.price <<"\n";
    os <<"ISBN #: " << book.isbn <<"\n";

    return os;
}

// TO DO: add <, >, <<
// CANT ALTER, ONLY ADD TO IT

/*
 int main() {

	cout <<"test main\n" <<endl;

	Book book("Girlboss", "Sophia Amoruso", 10.99, 12345);
	cout << book;



 }
*/

