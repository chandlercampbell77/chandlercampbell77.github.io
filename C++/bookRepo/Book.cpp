#include "Book.h"
Book::Book() // parameterless constructor sets to default values
{
    this->bookID = ""; //Empty string is something, nullptr is nothing - a big difference
    this->title = "";
    this->author = "";
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = 0;
    this->bookType = BookType::UNDECIDED;
}

Book::Book(string bookID, string title, string author, double prices[], BookType bookType)
{
    this->bookID = bookID;
    this->title = title;
    this->author = author;
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
    this->bookType = bookType;

}

Book::~Book() {} //destructor does nothing - the Book class creates nothing dynamically

// getters aka accessors
string Book::getID() { return this->bookID; }
string Book::getTitle() { return this->title; }
string Book::getAuthor() { return this->author; }
double* Book::getPrices() { return this->prices; } //An array name IS a pointer!
BookType Book::getBookType() { return this->bookType; }

// setters aka mutators
void Book::setID(string ID) { this->bookID = ID; }
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) { this->author = author; }
void Book::setPrices(double prices[]) //Set each price individually
{
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
}
void Book::setBookType(BookType bt) { this->bookType = bt; }

void Book::printHeader() //Use to print header
{
    cout << "Output format: ID|Title|Author|Prices|Type\n";
}

void Book::print()
{
    cout << this->getID() << '\t'; //Using tab separated output and getters
    cout << this->getTitle() << '\t';
    cout << this->getAuthor() << '\t';
    cout << this->getPrices()[0] << ',';
    cout << this->getPrices()[1] << ',';
    cout << this->getPrices()[2] << '\t';
    cout << bookTypeStrings[this->getBookType()] << '\n'; //Booktype to string
}