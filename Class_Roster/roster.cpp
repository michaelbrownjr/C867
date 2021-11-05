//
// Created by Michael Brown on 9/11/19.
//

#include <iostream>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

const string classRosterArray[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Michael,Brown,mbro549@wgu.edu,31,30,45,10,SOFTWARE"
};

//Function that checks the validity of an email address string
// Email is valid if "@" and "." is found, but invalid if an empty space is found also
bool isValidEmail (string email) {
    return email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos ? true
                                                                                                                 : false;
}

int main() {

    cout << "SCRIPTING AND PROGRAMMING APPLICATIONS: C867" << endl;
    cout << "C++ Programming Language" << endl;
    cout << "Student ID: 000861887" << endl;
    cout << "Michael Brown" << endl;

    Roster classRoster;
    Degree degree;

    // Looping through using a range based for-loop then parsing the data, adding the student data to the classRoster instance
    for (const auto & i : classRosterArray) {
        string value, data[9], place = i;
        istringstream ss(place);

        //  Parsing the data to enter the the array without any extra characters
        int index = 0;
        while (getline(ss, value, ',')) {
            data[index] = value;
            index += 1;
        }

        // If conditional statements checking the type
        if (!(data[8] == "SECURITY")) {
            if (data[8] == "SOFTWARE")
                degree = SOFTWARE;
            else
                degree = NETWORKING;
        } else degree = SECURITY;

        // Data is now being placed into the classRoster instance
        classRoster.add(data[0], data[1], data[2], data[3],
                        stoi(data[4]), stoi(data[5]), stoi(data[6]),
                        stoi(data[7]), degree);
    }

    // Prints the entire Student Data Table
    classRoster.printAll();
    // Prints the invalid emails within the Student data table
    classRoster.printInvalidEmails();

    // Looping through, using the range of the classRosterArray calling printDaysInCourse function
    // Printing how many days each student in the table have been in their respected courses
    for (auto & i : classRoster.classRosterArray) {
        classRoster.printDaysInCourse(i->getStudentID());
    }
    cout << endl;

    // Prints out those students in the class roster by a specific Degree program
    classRoster.printByDegreeProgram(SOFTWARE);
    // Removing student with a specific student ID calling the remove method
    classRoster.remove("A3");
    classRoster.remove("A3");
    // Destroys the instance using the destructor by calling the destructor
    classRoster.~Roster();

    return 0;
};

// Add method adding the properties into the new instance
// Sets the instance variables from part D1 and updates the roster
void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, Degree degree) {

    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] == nullptr) {
            switch (degree) {
                case SECURITY:
                    classRosterArray[i] = new securityStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                case SOFTWARE:
                    classRosterArray[i] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                case NETWORKING:
                    classRosterArray[i] = new networkStudent(studentID, firstName, lastName, emailAddress, age, days, degree);
                    break;
                default:
                    break;
            }
            break;
        }
    }

};

// Removes students from the roster by student ID.
// If the student ID does not exist, the function prints
// an error message indicating that the student was not found
// Requirement: studentID to be passed into this method
void Roster::remove(string studentID) {
    bool found = false;
    // For loop to traverse through the classRosterArray
    for (auto & i : classRosterArray) {
        if (i == nullptr || i->getStudentID() != studentID) continue;
        i = nullptr;
        found = true;
        break;
    }

    // Could use the ?: operator to clean up this if-else conditional statment
    if (found == false) {
        cout << "Error Removing Student! The student with the ID: " << studentID << " was not found in the system." << endl;
    } else {
        cout << studentID << " Removed." << endl;
    }
};

// Prints a complete tab-separated list of student data using accessor functions
void Roster::printAll() {
    for (auto & i : classRosterArray) {
        if (i != nullptr) {
            i->print();
        }
    }
    cout << endl;
};

// Prints a student’s average number of days in the three courses
// Requirement: studentID variable to be passed
void Roster::printDaysInCourse(string studentID) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getStudentID() == studentID) {
                const int * classes = classRosterArray[i]->getDaysToComplete();
                int average = (classes[0] + classes[1] + classes[2]) / 3;
                cout << studentID << " average: " << average << endl;
            }
        }
    }
};

// Verifies student email addresses and displays all invalid email addresses
// Calls isValidEmail boolean method to check for valid and invalid emails
void Roster::printInvalidEmails() {
    for (auto & i : classRosterArray) {
        if (i != nullptr && !isValidEmail(i->getEmailAddress())) {
            cout << i->getStudentID()
                 << " " << i->getEmailAddress()
                 << endl;
        }
    }
    cout << endl;
};
// Prints out all of students information by Degree Program/Type
void Roster::printByDegreeProgram(int degreeProgram) {
    for (auto & i : classRosterArray) {
        if (i != nullptr) {
            if (i->getDegreeType() == degreeProgram) {
                i->print();
            }
        }
    }
    cout << endl;
};
// Destructor to release the Roster memory
Roster::~Roster() {

};
