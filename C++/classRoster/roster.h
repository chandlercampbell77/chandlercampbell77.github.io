// E

#pragma once
#include "student.h"
using std::string;
using std::cout;
using std::endl;

class Roster
{
public:
    // Mirrors the index of the last student in the array, starting at -1 because no students yet
    int lastStudent = -1;
    const static int numStudents = 5;
    // E1
    Student* classRosterArray[numStudents];

public:
    // The parse method goes through the string and finds the values I am interested in

    // E2 a
    void parse(string line);

    // Adds a student to the Roster object

    // E2 b, E2 a
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);

    // E3 b
    void remove(string studentID); //Find the student by their ID and remove them
    // E3 c
    void printAll(); //Calls the print() method in Student class for every object
    // E3 d
    void printAverageDaysInCourse(string studentID); //Prints the average days remaining in courses for a given student
    // E3 e
    void printInvalidEmails(); //A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
    // E3 f
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};