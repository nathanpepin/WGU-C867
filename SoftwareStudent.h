#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <string>
#include "Student.h"
#include "Degree.h"
using namespace std;

class SoftwareStudent : public Student {
public:
    SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3, Degree iDegree);
    Degree getDegree() override;
};

#endif /* SECURITYSTUDENT_H */