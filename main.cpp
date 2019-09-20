#include <cstdlib>
#include <iostream>
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"

using namespace std;

int main() {
    Roster classRoster = Roster();
    classRoster.add("A1", "John", "Smith", "John1989@g mail.com", 20, 30, 35, 40, Degree::SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, Degree::NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, Degree::SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, Degree::SECURITY);
    classRoster.add("A5", "Nathan", "Pepin", "npepin1@wgu.edu", 28, 8, 15, 25, Degree::SOFTWARE);

    classRoster.printAll();

    classRoster.printInvalidEmails();
    classRoster.printAverageDaysInCourse("A5");

    classRoster.printByDegreeProgram("SOFTWARE");

    classRoster.remove("A3");
    classRoster.remove("A3");

    return 0;
}