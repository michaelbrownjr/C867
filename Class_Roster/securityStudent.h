//
// Created by Michael Brown on 9/11/19.
//

#ifndef CLASS_ROSTER_SECURITYSTUDENT_H
#define CLASS_ROSTER_SECURITYSTUDENT_H

#include <stdio.h>
#include "./student.h"


class securityStudent : public Student {

   using Student::Student;
public:
    virtual Degree getDegreeType();
private:
    Degree degreeType = SECURITY;
};


#endif //CLASS_ROSTER_SECURITYSTUDENT_H
