#include <iostream>
#include <stdio.h>
#include "string.h"
#include "Degree.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"

using namespace std;

Roster::Roster() {
    classSize = 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    //Ensures that there is never an array out of bounds error
    if (classSize > MAX_NUMBER_OF_STUDENTS - 1) {
        cout << "Error: The system limits the max number of students to be created to 100. Please contact the system admin";
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
    
    int indexToRemove = -1;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            cout << "\nError: Student ID entered not found\n\n";
            return;
        }
        
        //The classSize variable is not reduced because classSize essentially keeps track of the array index
        //It is not indicative of the current class size, but more the total class size ever
        //Further implementation could be provided which would put the array into a vector to allow for flexible use, but that is outside the scope of this project
        if (!classRosterArray[i]->getStudentID().compare(studentID)) {
            indexToRemove = i;
            classRosterArray[i] = nullptr;
            break;
        }
    }

    //Error handling
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
        //Ignore if student was delted
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
        //Ignore deleted students
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
    //If at least one '@' or one '.' is found we assume the email not invalid 
    bool foundAt = false;
    bool foundDot = false;

    for (int i = 0; i < iEmail.length(); i++) {
        switch (iEmail[i]) {
            //Invalid if any email has a space
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
    //Goes through entire class
    for (int i = 0; i < classSize; i++) {
        //Ignore deleted class members
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

    //Goes through entire class
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


//----------------------------------------------------
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                Main  Function
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//----------------------------------------------------

#define STUDENT_DATA_SIZE 5

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Nathan,Pepin,npepin@wgu.edu,28,8,15,25,SOFTWARE"
};

//Defined in global scope to provide access in function and to reduce clutter in the main function
Roster classRoster = Roster();

//Reads the roster string element and adds to classRoster
void readRosterString(char inputString[]) {
    //Expecting 9 different data elements in string array
    string output[9];

    //Divides string into different elements through use of the ","
    int i = 0;
    char *token = strtok(inputString, ",");
    while (token != NULL) {
        //Error checks for too many parameters
        if (i > 8) {
            cout << "\nError: Too many parameters for student. Student not added";
            return;
        }
        
        output[i++] = token;
        token = strtok(NULL, ",");
    }

    //Assigns and converts string array into properly named variables
    //Done for ease of reading
    string studentID = output[0];
    string firstName = output[1];
    string lastName = output[2];
    string email = output[3];
    int age = stoi(output[4]);
    int day1 = stoi(output[5]);
    int day2 = stoi(output[6]);
    int day3 = stoi(output[7]);
    string inputDegree = output[8];

    //Determines the degree type and error checks in case data is invalid
    if (!inputDegree.compare("SECURITY")) {
        classRoster.add(studentID, firstName, lastName, email, age, day1, day2, day3, Degree::SECURITY);
    } else if (!inputDegree.compare("NETWORK")) {
        classRoster.add(studentID, firstName, lastName, email, age, day1, day2, day3, Degree::NETWORK);
    } else if (!inputDegree.compare("SOFTWARE")) {
        classRoster.add(studentID, firstName, lastName, email, age, day1, day2, day3, Degree::SOFTWARE);
    } else {
        cout << "\nError: Degree invalid. Student not added";
    }
}

int main() {
    cout << "----------------------------------------------------\n";
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "----------------------------------------------------\n";
    cout << "Scripting and Programming - Applications – C867\n";
    cout << "Programming Language: C++\n";
    cout << "Student ID: #001195100\n";
    cout << "Name: Nathan Pepin\n";
    cout << "----------------------------------------------------\n";
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "----------------------------------------------------\n";


    //Goes through student data and adds to the roster
    for (int j = 0; j < STUDENT_DATA_SIZE; j++) {
        //Create temporary variables for data type conversion
        string record_string;
        char record_char[1024];
        
        record_string = studentData[j];
        
        //Converts string into char array in order to use strtok function
        strcpy(record_char, record_string.c_str());
        
        //Inputs into function to interpret and add to roster
        readRosterString(record_char);
    }

    //Base functionality of program
    classRoster.printAll();

    classRoster.printInvalidEmails();
    
    classRoster.printAverageDaysInCourse("A5");

    classRoster.printByDegreeProgram(Degree::SOFTWARE);

    classRoster.remove("A3");
    classRoster.remove("A3");

    return 0;
}