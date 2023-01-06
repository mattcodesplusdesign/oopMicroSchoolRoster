#include "roster.h"
#include <regex>
#include <iostream>
#include <string>
#
#include <sstream>



    // Constructor
    Roster::Roster()

    {
    // Initialize all elements of the array to nullptr
    for (int i = 0; i < 5; i++)
    {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster()
{
    // Delete all student objects from the array
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }


}

Student Roster::parse(std::string input_string) {
    std::stringstream ss(input_string);
    std::string item;

    std::getline(ss, item, ',');
    std::string studentId = item;

    std::getline(ss, item, ',');
    std::string firstName = item;

    std::getline(ss, item, ',');
    std::string lastName = item;

    std::getline(ss, item, ',');
    std::string email = item;

    std::getline(ss, item, ',');
    int age = std::stoi(item);

    std::getline(ss, item, ',');
    int daysInCourse1 = std::stoi(item);

    std::getline(ss, item, ',');
    int daysInCourse2 = std::stoi(item);

    std::getline(ss, item, ',');
    int daysInCourse3 = std::stoi(item);

    std::getline(ss, item, ',');
    std::string degreeSpecialtyString = item;
    DegreeSpecialty degreeSpecialty = DegreeSpecialty::UNKNOWN;
    if (degreeSpecialtyString == "SECURITY") {
        degreeSpecialty = DegreeSpecialty::SECURITY;
    }
    else if (degreeSpecialtyString == "NETWORK") {
        degreeSpecialty = DegreeSpecialty::NETWORK;
    }
    else if (degreeSpecialtyString == "SOFTWARE") {
        degreeSpecialty = DegreeSpecialty::SOFTWARE;
    }
    // Create a new Student object using the extracted attributes
    Student newStudent(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeSpecialty);
    return newStudent;
}


void Roster::printAll() const
{
    // Loop through all the students in classRosterArray and call the print function for each student
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
}



// Add a student to the roster
void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeSpecialty degreeSpecialty) {
    // Create a new student object using the parsed data
    Student* newStudent = new Student(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeSpecialty);

    // Add the new student object to the roster
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = newStudent;
            break;
        }
    }
}

  




void Roster::remove(std::string studentId)
{
    // Flag to track whether the student was found
    bool studentFound = false;

    // Search the array for the student
    for (int i = 0; i < 5; i++)
    {
        // Check if the current element is the student we are looking for
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getId() == studentId)
        {
            // Delete the student object
            delete classRosterArray[i];

            // Set the element to nullptr to indicate that it is empty
            classRosterArray[i] = nullptr;

            // Set the studentFound flag to true
            studentFound = true;

            // Output a message to the console
            std::cout << "Student with ID " << studentId << "was removed from the roster." << std::endl;

            // We found the student, so we can stop searching
            break;
        }
    }

    // If the student was not found, output an error message
    if (!studentFound)
    {
        std::cerr << "Error: Student with ID " << studentId << " was not found on the roster." << std::endl;
    }
}

void Roster::printAverageDaysInCourse(std::string studentId)
{
    // Find the student with the specified student ID
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getId() == studentId)
        {
            // Get the number of days in each course for the current student
            int* daysInCourse = classRosterArray[i]->getDaysInCourse();

            // Calculate and print the average number of days in the three courses
            int averageDaysInCourse = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
            std::cout << "Average days in course for student with ID " << studentId << ": " << averageDaysInCourse << std::endl;
            break;
        }
    }
}

void Roster::printInvalidEmails()
{

    // Use a regular expression to check if an email address is valid
    std::regex emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");

    // Loop through all the students in the array
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            // Get the email address of the current student
            std::string email = classRosterArray[i]->getEmail();

            // Check if the email address is invalid (i.e., does not match the regular expression)
            if (!std::regex_match(email, emailRegex))
            {
                // Print the invalid email address to the console
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }


}

void Roster::printByDegreeProgram(DegreeSpecialty degreeSpecialty)
{
    // Loop through all the students in the classRosterArray
    for (int i = 0; i < 5; i++)
    {
        // Check if the student's degree specialty matches the one passed in as an argument
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeSpecialty() == degreeSpecialty)
        {
            // Print the student's information to the console
            classRosterArray[i]->print();
        }
    }
}
