cmake_minimum_required(VERSION 3.14)
project(Class_Roster)

set(CMAKE_CXX_STANDARD 11)

add_executable(Class_Roster degree.h student.cpp student.h networkStudent.cpp networkStudent.h securityStudent.cpp securityStudent.h softwareStudent.cpp softwareStudent.h roster.cpp roster.h)