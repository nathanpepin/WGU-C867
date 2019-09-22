#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Degree.h"

using namespace std;

#define MAX_NUMBER_OF_STUDENTS 100

class Roster
{

private:
    //A max of 100 students is somewhat arbitrary, but at the same time limiting the array to 5 doesn't make sense
    //Using a vector type could help make the program more dynamic, but the assignment calls for an array with pointers
    Student* classRosterArray[MAX_NUMBER_OF_STUDENTS];
    int classSize;

public:
    Roster();

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    bool checkIfInvalidEmail(string iEmail);

    void printInvalidEmails();

    void printByDegreeProgram(Degree degreeProgram);
    
    ~Roster();
};

#endif /* ROSTER_H */

