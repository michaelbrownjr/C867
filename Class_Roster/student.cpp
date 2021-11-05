//
// Created by Michael Brown on 9/11/19.
//

#include "student.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
Student::Student(string id, string fName, string lName, string eMail, int age, int days[3], Degree degree) {
    setStudentID(id);
    setFirstName(fName);
    setLastName(lName);
    setEmailAddress(eMail);
    setAge(age);
    setDaysToComplete(days);
    setDegreeType(degree);
};

// Destructor
Student::~Student() {};

// Accessors
string Student::getStudentID() const {
    return studentID;
};
string Student::getFirstName() const {
    return firstName;
};
string Student::getLastName() const {
    return lastName;
};
string Student::getEmailAddress() const {
    return emailAddress;
};
int Student::getAge() const {
    return age;
};
const int * Student::getDaysToComplete() const {
    return daysToComplete;
};

Degree Student::getDegreeType() {
    return degreeType;
};

// Mutators
void Student::setStudentID(string id) {
    studentID = id;
};
void Student::setFirstName(string fName){
    firstName = fName;
};
void Student::setLastName(string lName) {
    lastName = lName;
};
void Student::setEmailAddress(string eMail) {
    emailAddress = eMail;
};
void Student::setAge(int studentAge) {
    age = studentAge;
};
void Student::setDaysToComplete(int *days) {
    for (int i = 0; i < 3; i++) {
        daysToComplete[i] = days[i];
    }
};
void Student::setDegreeType(Degree degree) {
    degreeType = degree;
};

void Student::print(){

    string degree;

    if (getDegreeType() == 0)
        degree = "Security";
    else if (getDegreeType() == 1)
        degree = "Network";
    else if (getDegreeType() == 2)
        degree = "Software";

    cout << getStudentID() << "\t"
         << "First Name: " << getFirstName() << "\t"
         << "Last Name: " << getLastName() << "\t"
         << "Email Address: " << getEmailAddress() << "\t"
         << "Age: " << getAge() << " "
         << "Days In Course: { " << getDaysToComplete()[0] << ", "
         << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << " } \t"
         << "Degree Program: " << degree
         << endl;

};

