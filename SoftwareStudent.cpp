#include "SoftwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3, Degree iDegree)
: Student(studentID, firstName, lastName, email, age, daysTC1, daysTC2, daysTC3) {
    setDegree(iDegree);
};

Degree SoftwareStudent:: getDegree() {
    return Degree::SOFTWARE;
}