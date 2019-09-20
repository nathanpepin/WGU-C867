#include <iostream>
#include "Roster.h"
#include "Degree.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"

using namespace std;

Roster::Roster() {
    classSize = 0;
}

void Roster::add(string studentID, string firstName,
        string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    classSize++;
    if (degree == Degree::SECURITY) {
        classRosterArray.push_back(SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
    } else if (degree == Degree::NETWORK) {
        classRosterArray.push_back(NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
    } else if (degree == Degree::SOFTWARE) {
        classRosterArray.push_back(SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3));
    } else {
        classSize--;
        cout << "Error: Degree type note found. Please re-enter with available degrees: SECURURITY, NETWORK, or SOFTWARE";
    }
}

void Roster::remove(string studentID) {
    cout << "\n----------------------------------------------------\n";
    cout << "Removing student: " << studentID << "\n";
    cout << "----------------------------------------------------";

    if (classSize < 1) {
        cout << "\nError: There are no students to remove";
    }

    int indexToRemove = -1;
    for (int i = 0; i < classSize; i++) {
        if (!classRosterArray[i].getStudentID().compare(studentID)) {
            indexToRemove = i;
            classSize--;
            classRosterArray.erase(classRosterArray.begin() + i);
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "\nError: Student ID entered not found\n";
    } else {
        cout << "\nStudent " << studentID << " removed\n";
    }
    cout << "\n";
}

void Roster::printAll() {
    cout << "\n----------------------------------------------------\n";
    cout << "Printing all students\n";
    cout << "----------------------------------------------------";
    for (int i = 0; i < classSize; i++) {
        classRosterArray[i].print();
    }
    cout << "\n";
}

void Roster::printAverageDaysInCourse(string studentID) {
    cout << "\n----------------------------------------------------\n";
    cout << "Printing average days in course for student: " << studentID << "\n";
    cout << "----------------------------------------------------";
    //Find student with particular ID
    int indexOfStudent = -1;
    for (int i = 0; i < classSize; i++) {
        if (!classRosterArray[i].getStudentID().compare(studentID)) {
            indexOfStudent = i;
            break;
        }
    }

    //Error handling
    if (indexOfStudent == -1) {
        cout << "\nError: Student ID entered not found\n";
        return;
    }

    //Averages
    double average = 0.0;
    int totalDays = 3;
    for (int j = 0; j < totalDays; j++) {
        average += classRosterArray[indexOfStudent].getDaysToComplete(j);
    }
    cout << "\nAverage: " << average / totalDays << "\n";
}

bool Roster::checkIfInvalidEmail(string iEmail) {
    const bool INVALID = true;
    bool foundAt = false;
    bool foundDot = false;

    for (int i = 0; i < iEmail.length(); i++) {
        switch (iEmail[i]) {
            case ' ':
                return INVALID;
            case '@':
                foundAt = true;
                break;
            case '.':
                foundDot = true;
                break;
        }
    }

    if (foundDot && foundAt)
        return false;
    else
        return INVALID;
}

void Roster::printInvalidEmails() {
    cout << "\n----------------------------------------------------\n";
    cout << "Printing invalid emails: \n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < classSize; i++) {
        if (checkIfInvalidEmail(classRosterArray[i].getEmail())) {
            cout << "Student ID: " << classRosterArray[i].getStudentID() << " Email: " << classRosterArray[i].getEmail() << "\n";
        }
    }
}

void Roster::printByDegreeProgram(string degreeProgram) {
    //Header
    cout << "\n----------------------------------------------------\n";
    cout << "Printing students by degree program: " << degreeProgram << "\n";
    cout << "----------------------------------------------------";

    //Error checking
    if (degreeProgram.compare("SECURITY") && degreeProgram.compare("NETWORK") && degreeProgram.compare("SOFTWARE")) {
        cout << "Error: Degree program not found";
    }

    //Printing
    for (int i = 0; i < classSize; i++) {
        /*if (!classRosterArray[i].getDegreeType().compare(degreeProgram))
        {
            classRosterArray[i].print();
        }*/
    }
    cout << "\n";
}
