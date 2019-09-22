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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    //Ensures that there is never an array out of bounds error
    if (classSize > MAX_NUMBER_OF_STUDENTS - 1) {
        cout << "Error: The system limits the max number of students to be created to 100. Please contact the system adminstrator";
        return;
    }
    
    if (degree == Degree::SECURITY) {
        classRosterArray[classSize++] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    } else if (degree == Degree::NETWORK) {
        classRosterArray[classSize++] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    } else if (degree == Degree::SOFTWARE) {
        classRosterArray[classSize++] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    } else {
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
        if (classRosterArray[i] == nullptr) {
            cout << "\nError: Student ID entered not found\n\n";
            return;
        }
        
        if (!classRosterArray[i]->getStudentID().compare(studentID)) {
            indexToRemove = i;
            classSize--;
            classRosterArray[i] = nullptr;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "\nError: Student ID entered not found\n";
    } else {
        cout << "\nStudent " << studentID << " removed\n";
    }
}

void Roster::printAll() {
    cout << "\n----------------------------------------------------\n";
    cout << "Printing all students\n";
    cout << "----------------------------------------------------";
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            break;
        }
        classRosterArray[i]->print();
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
        if (classRosterArray[i] == nullptr) {
            break;
        }
        if (!classRosterArray[i]->getStudentID().compare(studentID)) {
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
        average += classRosterArray[indexOfStudent]->getDaysToComplete(j);
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
        if (classRosterArray[i] == nullptr) {
            break;
        }
        if (checkIfInvalidEmail(classRosterArray[i]->getEmail())) {
            cout << "Student ID: " << classRosterArray[i]->getStudentID() << " Email: " << classRosterArray[i]->getEmail() << "\n";
        }
    }
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
    //Header
    cout << "\n----------------------------------------------------\n";
    cout << "Printing students by degree program\n";
    cout << "----------------------------------------------------";

    //Printing
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            break;
        }
        if (classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << "\n";
}

Roster::~Roster() {
    delete *classRosterArray;
    cout << "Roster object deconstructed";
}