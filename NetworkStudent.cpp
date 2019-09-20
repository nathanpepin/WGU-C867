#include "NetworkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3)
: Student(studentID, firstName, lastName, email, age, daysTC1, daysTC2, daysTC3) {
    //setDegree(Degree::NETWORK);
};

Degree NetworkStudent:: getDegree() {
    return Degree::NETWORK;
}