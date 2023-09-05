#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;

// D1
class Student
{
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[daysArraySize];
    DegreeProgram degreeProgram;
public:
    // D2
    Student(); // default constructor
    Student(string bookID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram); // complete constructor
    ~Student(); // destructor

    // getters(accessors)
    string getID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    // setters(mutators)
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    static void printHeader(); // prints the columns of the data

    void print(); //displays a given's student's information
};