// E

#include "roster.h"
#include <cstring>
#include <string>
using std::endl;
using std::string;
using std::cout;
using std::stoi;

// E2 a
void Roster::parse(string line)
{
    // Using an algorithm to find the values I am interested in, relying upon commas

    int right = line.find(",");
    string studentID = line.substr(0, right);

    int left = right + 1;
    right = line.find(",", left);
    string firstName = line.substr(left, right - left);

    left = right + 1;
    right = line.find(",", left);
    string lastName = line.substr(left, right - left);

    left = right + 1;
    right = line.find(",", left);
    string emailAddress = line.substr(left, right - left);

    left = right + 1;
    right = line.find(",", left);
    int age = stod(line.substr(left, right - left));

    left = right + 1;
    right = line.find(",", left);
    int daysInCourse1 = std::stoi(line.substr(left, right - left)); // convert to int because it is currently a string
    left = right + 1;
    right = line.find(",", left);
    int daysInCourse2 = std::stoi(line.substr(left, right - left));
    left = right + 1;
    right = line.find(",", left);
    int daysInCourse3 = std::stoi(line.substr(left, right - left));

    left = right + 1;
    right = line.find(",", left);
    string program = line.substr(left, right - left);
    DegreeProgram degreeProgram = SECURITY;
    if (program.compare("NETWORK") == 0)
    {
        degreeProgram = NETWORK;
    }
    else if (program.compare("SOFTWARE") == 0)
    {
        degreeProgram = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


// E3 a
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    //Put daysInCourses into an array
    int daysArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

    //Initializing a Student object
    classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

// E3 b
void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= Roster::lastStudent; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            found = true; //located the student in the array
            // No point in swapping last element with itself
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastStudent--; // This effectively deletes the student
        }
    }
    if (found)
    {
        cout << studentID << " removed from the roster." << endl << endl;
    }
    else cout << studentID << " not found." << endl << endl;
}

//Display the students using tabs

// E3 c
void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastStudent; i++)
    {
       classRosterArray[i]->print();
    }
}

// E3 d
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (classRosterArray[i]->getID() == studentID)
        {
            cout << classRosterArray[i]->getID() << ": ";
            cout << (classRosterArray[i]->getDays()[0]
            + classRosterArray[i]->getDays()[1]
            + classRosterArray[i]->getDays()[2])/3.0 << endl;

        }
    }
}

// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')

// E3 e
void Roster::printInvalidEmails()
{
    bool foundInvalidEmailAddress = false;
    for (int i = 0; i <= Roster::lastStudent; i++)
    {
        string emailAddress = (classRosterArray[i]->getEmailAddress());
        if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(" ") != string::npos)
        {
            foundInvalidEmailAddress = true;
            cout << "Invalid email: " << emailAddress << endl;
        }
    }
    if (!foundInvalidEmailAddress) cout << "No invalid emails found" << endl;
}

// Prints the students that are in a given degree program

// E3 f
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for (int i = 0; i < numStudents; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) Roster::classRosterArray[i]->print();
    }
    cout << endl;
}

Roster::~Roster()
{
    cout << "DESTRUCTOR CALLED!!!" << endl << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] == nullptr;
    }
}