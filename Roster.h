#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Degree.h"

using namespace std;

class Roster
{

private:
    vector<Student> classRosterArray;
    int classSize;

public:
    Roster();

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    bool checkIfInvalidEmail(string iEmail);

    void printInvalidEmails();

    void printByDegreeProgram(string degreeProgram);
};

#endif /* ROSTER_H */

