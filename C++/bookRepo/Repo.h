#pragma once
#include "Book.h"
class Repo
{
public: // MOD OCTOBER 3 2020 - used to be private
    int lastIndex = -1;
    const static int numBooks = 5;
    Book* bookRepoArray[numBooks]; // NOT declared dynamically

public:
    // Note that Repo has no constructor; or DOES IT...?
    // The parse method goes through a set of comma delimited strings and extracts the data of a book
    void parse(string row);
    //All book data is then passed into the add method which creates a Book object and places it in the repo
    void add(string bID,
        string bTitle,
        string bAuthor,
        double bprice1,
        double bprice2,
        double bprice3,
        BookType bt);
    void printAll(); //Just calls the print() method in Book class for each book
    void printByBookType(BookType bt); //BookType is passed in
    void printInvalidIDs(); //Each book's ID needs an underscore and either an upper case 'X' or lower case 'x'
    void printAveragePrices(string bookID); //Prints the average price for each book
    void removeBookByID(string bookID); //Find the book with the supplied ID and remove
    ~Repo();
};