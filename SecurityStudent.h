#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <string>
#include "Student.h"
#include "Degree.h"
using namespace std;

class SecurityStudent : public Student {
public:
    SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int daysTC1, int daysTC2, int daysTC3);
    Degree getDegree() override;
};

#endif /* SECURITYSTUDENT_H */