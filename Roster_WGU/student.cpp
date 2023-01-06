#include "student.h"



//constructor
Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeSpecialty degreeSpecialty)
    :studentId(studentId), firstName(firstName), lastName(lastName), email(email), age(age), degreeSpecialty(degreeSpecialty)
{
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}
//destructor
Student::~Student()
{
}




//getters

std::string Student::getId() const
{
    return studentId;
}

std::string Student::getFirstName() const
{
    return firstName;
}

std::string Student::getLastName() const
{
    return lastName;
}

std::string Student::getEmail() const
{
    return email;
}

int Student::getAge() const
{
    return age;
}

int* Student::getDaysInCourse()
{
    return daysInCourse;
}

DegreeSpecialty Student::getDegreeSpecialty() const
{
    return degreeSpecialty;
}
//setters
void Student::setId(std::string studentId)
{
    this->studentId = studentId;
}

void Student::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(std::string email)
{
    this->email = email;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeSpecialty(DegreeSpecialty degreeSpecialty)
{
    this->degreeSpecialty = degreeSpecialty;
}


void Student::print() const
{
    // Print the student's information
    std::cout << "ID: " << studentId << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Days in Course: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << std::endl;
    std::cout << "Degree Specialty: ";
    switch (degreeSpecialty)
    {
    case DegreeSpecialty::SECURITY:
        std::cout << "Security" << std::endl;
        break;
    case DegreeSpecialty::NETWORK:
        std::cout << "Network" << std::endl;
        break;
    case DegreeSpecialty::SOFTWARE:
        std::cout << "Software" << std::endl;
        break;
    }
}