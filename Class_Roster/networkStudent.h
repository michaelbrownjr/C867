//
// Created by Michael Brown on 9/11/19.
//

#ifndef CLASS_ROSTER_NETWORKSTUDENT_H
#define CLASS_ROSTER_NETWORKSTUDENT_H

#include <stdio.h>
#include "./student.h"

class networkStudent : public Student {
    using Student::Student;
public:
    virtual Degree getDegreeType();
private:
    Degree degreeType = NETWORKING;
};


#endif //CLASS_ROSTER_NETWORKSTUDENT_H
