#include "roster.h"
using std::string;
using std::cout;
using std::endl;


int main()
{
    // F1
    cout << endl;
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011247597" << endl;
    cout << "Name: Chandler Campbell" << endl;

    // The provided student data with my info included in A5
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chandler,Campbell,ccam734@wgu.edu,24,15,30,35,SOFTWARE"
    };

    const int numStudents = 5;

    // F2
    Roster classRoster; // creating an instance of the Roster class

    // F3
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

    // F4
    cout << endl;
    cout << "Displaying all students: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying students with invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in course of each student: " << endl;
    //loop through classRosterArray and for each element:
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << endl;


    cout << "Displaying by SOFTWARE degree program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);


    cout << "Removing student with ID 'A3':" << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    cout << endl;

    // F5
    cout << "Press and enter any key to call destructor..." << endl;
    std::cin.get();
    return 0;
}