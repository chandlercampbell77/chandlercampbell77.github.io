#include "Repo.h"
void Repo::parse(string bookdata) //this parses out each row - one at a time
{
    BookType bt = UNDECIDED; //default value
    if (bookdata.at(0) == 'F') bt = FICTION; //the first character tells us the book type
    else if (bookdata.at(0) == 'N') bt = NONFICTION;

    int rhs = bookdata.find(","); //find the comma
    string bID = bookdata.substr(0, rhs); //extract the substring in front of the comma

    int lhs = rhs + 1; //move past the previous comma
    rhs = bookdata.find(",", lhs);
    string ttl = bookdata.substr(lhs, rhs - lhs); //book title

    lhs = rhs + 1; //keep going
    rhs = bookdata.find(",", lhs);
    string aut = bookdata.substr(lhs, rhs - lhs); //book author

    lhs = rhs + 1; //keep going
    rhs = bookdata.find(",", lhs);
    double p1 = stod(bookdata.substr(lhs, rhs - lhs)); //first price - convert to double
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p2 = stod(bookdata.substr(lhs, rhs - lhs)); //second price
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p3 = stod(bookdata.substr(lhs, rhs - lhs)); //third price

    //Already determined the book type - it was the first thing we did - call add() method

    add(bID, ttl, aut, p1, p2, p3, bt); //prices go in SEPARATELY
}

//The infamous, redundant, and wholly unnecessary add method - it only does one thing
void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, BookType bt)
{
    //Put prices back into an array for constructor - OK, it does TWO things!
    double parr[3] = { price1,price2,price3 };
    //Make the new Book object. Remember that lastIndex starts at -1 and NOT 0
    //Remember to use the PREFIX form of ++. Using postfix will MESS YOU UP!
    bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);
}

//Display all books using tab-seperated output
void Repo::printAll()
{
    Book::printHeader(); //quick way to do this part
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        cout << bookRepoArray[i]->getID(); cout << '\t'; //Using tab separated output and getters
        cout << bookRepoArray[i]->getTitle(); cout << '\t';
        cout << bookRepoArray[i]->getAuthor(); cout << '\t';
        cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
        cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl; //Booktype to string
    }
}

//display only books which match a given book type
void Repo::printByBookType(BookType bt)
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
    }
    cout << std::endl;
}

// Each book's ID must contain and underscore and either an upper case 'X' or lower case 'x'
void Repo::printInvalidIDs()
{
    bool any = false;
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        string bID = (bookRepoArray[i]->getID());
        if (bID.find('_') == string::npos || bID.find('X') == string::npos && bID.find('x') == string::npos)
        {
            any = true;
            cout << bID << ": " << bookRepoArray[i]->getTitle() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Repo::printAveragePrices(string bookID)
{
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (bookRepoArray[i]->getID() == bookID)
        {
            cout << bookRepoArray[i]->getID() << ": ";
            cout << (bookRepoArray[i]->getPrices()[0]
            + bookRepoArray[i]->getPrices()[1]
            + bookRepoArray[i]->getPrices()[2])/3.0 << std::endl;

        }
    }
}

void Repo::removeBookByID(string bookID) //book to be removed comes in as a parameter
{
    bool success = false; //assume it's NOT here
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        if (bookRepoArray[i]->getID() == bookID)
        {
            success = true; //found
            if (i < numBooks - 1)
            {
                Book* temp = bookRepoArray[i]; //swap it with last book
                bookRepoArray[i] = bookRepoArray[numBooks - 1];
                bookRepoArray[numBooks - 1] = temp;
            }
            Repo::lastIndex--; //LAST BOOK NO LONGER VISIBLE
            // NOTICE I DID NOT ACTUALLY DELETE THE BOOK! YOU JUST CAN'T SEE IT NOW!
        }
    }
    if (success)
    {
        cout << bookID << " removed from the repositroy." << std::endl << std::endl;
        this->printAll(); //display the books - the removed one SHOULD NOT DISPLAY
    }
    else cout << bookID << " not found." << std::endl << std::endl;
}

Repo::~Repo()
{
    cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
    for (int i = 0; i < numBooks; i++)
    {
        cout << "Destroying book #" << i + 1 << std::endl;
        delete bookRepoArray[i];
        bookRepoArray[i] == nullptr;
    }
}