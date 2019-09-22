#include <iostream>
#include<vector>
#include <string.h>
#include <stdio.h>
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"
#include "Degree.h"

using namespace std;

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