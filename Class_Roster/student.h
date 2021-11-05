//
// Created by Michael Brown on 9/11/19.
//

#ifndef CLASS_ROSTER_STUDENT_H
#define CLASS_ROSTER_STUDENT_H

#include <stdio.h>
#include <string>
#include "./degree.h"
 using namespace std;


class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    Degree degreeType;

public:
    Student(string, string, string, string, int, int [3], Degree);
    ~Student();

    //List of mutators
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setDaysToComplete(int*);
    void setDegreeType(Degree);

    //List of accessors
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int *getDaysToComplete() const ;

    virtual Degree getDegreeType();
    virtual void print();
};


#endif //CLASS_ROSTER_STUDENT_H
