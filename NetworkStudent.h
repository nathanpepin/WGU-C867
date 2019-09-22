#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <string>
#include "Student.h"
#include "Degree.h"
using namespace std;

class NetworkStudent : public Student {
public:
    NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3, Degree iDegree);
    Degree getDegree() override;
};

#endif /* NETWORKSTUDENT_H */

