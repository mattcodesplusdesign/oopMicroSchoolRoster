#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "degree.h"


#ifndef ROSTER_H
#define ROSTER_H

class Roster
{


public:

    // Array of pointers to hold the student data
    Student* classRosterArray[5];
    // Constructor
    Roster();

    // Destructor
    ~Roster();


    Student parse(std::string input_string);
    //print all students stored in pointer
  
    // Add a student to the roster
    void add(std::string studentId, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeSpecialty degreeSpecialty);
    void printAll() const;
    
    void remove(std::string studentId);

    void printAverageDaysInCourse(std::string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeSpecialty);



};


#endif