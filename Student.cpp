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
};

void Student::print() {
    cout << "\nStudent ID: " << getStudentID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Email: " << getEmail() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Day To Complete: " << getDaysToComplete(0) << ", " << getDaysToComplete(1) << ", " << getDaysToComplete(2) << "\t";
    cout << "Degree: " << printDegree();
}

//Converts the degree into a string to allow for easier printing
string Student::printDegree() {
    switch (getDegree()) {
        case Degree::SECURITY: return "SECURITY";
        case Degree::NETWORK: return "NETWORK";
        case Degree::SOFTWARE: return "SOFTWARE";
        defaul: cout << "Error: Degree not found";
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
}

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

Student::~Student() {
}

