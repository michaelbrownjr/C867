//
// Created by Michael Brown on 9/11/19.
//

#ifndef CLASS_ROSTER_SOFTWARESTUDENT_H
#define CLASS_ROSTER_SOFTWARESTUDENT_H

#include <stdio.h>
#include "./student.h"


class softwareStudent : public Student {
    using Student::Student;
public:
    virtual Degree getDegreeType();
private:
    Degree degreeType = SOFTWARE;
};


#endif //CLASS_ROSTER_SOFTWARESTUDENT_H
