#pragma once
#include <iostream>
#include <string>
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"

class Student {
public:
    Student(std::string studentId, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeSpecialty degreeSpecialty);
    ~Student();

    std::string getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    int getAge() const;
    int* getDaysInCourse();

    DegreeSpecialty getDegreeSpecialty() const;

    void setId(std::string studentId);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeSpecialty(DegreeSpecialty degreeSpecialty);

    void print() const;


private:
    std::string studentId;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
    DegreeSpecialty degreeSpecialty;
};

#endif
