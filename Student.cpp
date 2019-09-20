#include "Student.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Degree.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3) {
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    setDaysToComplete(daysTC1, daysTC2, daysTC3);
    //degree = Degree::NONE;
};

void Student::print() {
    cout << "\n\nStudent Information\n";
    cout << "--------------------------\n";
    cout << "Student ID: " << getStudentID() << "\n";
    cout << "First Name: " << getFirstName() << "\n";
    cout << "Last Name: " << getLastName() << "\n";
    cout << "Email: " << getEmail() << "\n";
    cout << "Age: " << getAge() << "\n";
    cout << "Day To Complete: " << getDaysToComplete(0) << ", " << getDaysToComplete(1) << ", " << getDaysToComplete(2) << "\n";
    cout << "Degree: " << printDegree();
}

string Student::printDegree() {
    switch (Student::getDegree()) {
        case Degree::SECURITY: return "SECURITY";
        case Degree::NETWORK: return "NETWORK";
        case Degree::SOFTWARE: return "SOFTWARE";
        case Degree::NONE: return "NONE";
    }
}

//GETTERS

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int Student::getDaysToComplete(int day) {
    return daysToComplete[day];
}

Degree Student::getDegree() {
    return Degree::NONE;
};

//SETTERS

void Student::setStudentID(string iStudentID) {
    studentID = iStudentID;
}

void Student::setFirstName(string iFirstName) {
    firstName = iFirstName;
}

void Student::setLastName(string iLastName) {
    lastName = iLastName;
}

void Student::setEmail(string iEmail) {
    email = iEmail;
}

void Student::setAge(int iAge) {
    age = iAge;
}

void Student::setDaysToComplete(int iDays1, int iDays2, int iDays3) {
    daysToComplete[0] = iDays1;
    daysToComplete[1] = iDays2;
    daysToComplete[2] = iDays3;
}

//void Student::setDegree(Degree iDegree) {
//    degree = iDegree;
//}

Student::~Student() {
}

