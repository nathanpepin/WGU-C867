#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Degree.h"
using namespace std;

class Student {
private:
    string studentID, firstName, lastName, email;
    int age;
    int daysToComplete[3];
    Degree degree;

public:
    Student(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3);

    void print();
    string printDegree();

    //GETTERS
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int getDaysToComplete(int day);
    virtual Degree getDegree();

    //SETTERS
    void setStudentID(string iStudentID);
    void setFirstName(string iFirstName);
    void setLastName(string iLastName);
    void setEmail(string iEmail);
    void setAge(int iAge);
    void setDaysToComplete(int iDays1, int iDays2, int iDays3);
    void setDegree(Degree iDegree);

    ~Student();
};

#endif /* STUDENT_H */

