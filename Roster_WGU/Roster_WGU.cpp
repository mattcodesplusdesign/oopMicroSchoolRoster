
#include <iostream>
#include <sstream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main(){ 
    std::cout << "Created by Matthew Landeros Guillen" << std::endl;
    std::cout << "Scripting and Programming in C++" << std::endl;
    std::cout << "StudentID:mland66" << std::endl;
    // Create a roster object
  
    const std::string studentData[] = {"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
                                     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         
        "A5,Matthew,Landeros Guillen,mland66@wgu.edu26, 20,30,40,SOFTWARE"};

  
    Roster classRoster;
    Roster roster;





   //These were incremental test to ensure every component of the program would work. Refer back to these if needed at any point. Many of the test have been removed to avoid confusion.

    //Create a student instance

        Student student("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, DegreeSpecialty::SECURITY);

     // TEST Print the student information using the getters
        std::cout << "Student ID: " << student.getId() << std::endl;
        std::cout << "First name: " << student.getFirstName() << std::endl;
        std::cout << "Last name: " << student.getLastName() << std::endl;
        std::cout << "Email: " << student.getEmail() << std::endl;
        std::cout << "Age: " << student.getAge() << std::endl;
        int* daysInCourse = student.getDaysInCourse();
        std::cout << "Days in course 1: " << daysInCourse[0] << std::endl;
        std::cout << "Days in course 2: " << daysInCourse[1] << std::endl;
        std::cout << "Days in course 3: " << daysInCourse[2] << std::endl;
        std::cout << "Degree specialty: " << static_cast<int>(student.getDegreeSpecialty()) << std::endl;
    // TEST Update the student information using the setters
        student.setId("A2");
        student.setFirstName("Suzan");
        student.setLastName("Erickson");
        student.setEmail("Erickson_1990@gmail.com");
        student.setAge(19);
        student.setDaysInCourse(50, 30, 40);
        student.setDegreeSpecialty(DegreeSpecialty::NETWORK);
     // TEST Print the updated student information
        std::cout << "\nUpdated student information:" << std::endl;
        std::cout << "Student ID: " << student.getId() << std::endl;
        std::cout << "First name: " << student.getFirstName() << std::endl;
        std::cout << "Last name: " << student.getLastName() << std::endl;
        std::cout << "Email: " << student.getEmail() << std::endl;
        std::cout << "Age: " << student.getAge() << std::endl;
        daysInCourse = student.getDaysInCourse();
        std::cout << "Days in course 1: " << daysInCourse[0] << std::endl;
        std::cout << "Days in course 2: " << daysInCourse[1] << std::endl;
        std::cout << "Days in course 3: " << daysInCourse[2] << std::endl;
        std::cout << "Degree specialty: " << static_cast<int>(student.getDegreeSpecialty()) << std::endl;


        // TEST Add a student to the roster
        roster.add("A1", "John", "Doe", "john@email.com", 20, 90, 80, 70, DegreeSpecialty::SECURITY); // Add a student to the roster
        roster.add("A2", "Jane", "Doe", "jane@email.com", 21, 80, 70, 60, DegreeSpecialty::NETWORK); // Add a student to the roster
        roster.add("A3", "Bob", "Smith", "bob@email.com", 22, 70, 60, 50, DegreeSpecialty::SOFTWARE); // Add a student to the roster

        // Print all students in the roster
        for (int i = 0; i < 5; i++)
        {
            if (roster.classRosterArray[i] != nullptr)
            {
                roster.classRosterArray[i]->print();
            }
        }
    //This will print the information for all the students in the classRosterArray
        roster.printAll();

        // Remove the student from the roster
        roster.remove("A1");


        // Call the print function on the student object
        student.print();


      // Print the average number of days in the three courses for the student with student ID "A1"
        roster.printAverageDaysInCourse("A1");
        roster.printAverageDaysInCourse("A2");
        roster.printAverageDaysInCourse("A3");
    







    











    /*


    for (int i = 0; i < 5; i++) {
        Student newStudent = classRoster.parse(studentData[i]);
        classRoster.add(newStudent.getId(),newStudent.getFirstName(),newStudent.getLastName(), newStudent.getEmail(), newStudent.getAge(), newStudent.getDaysInCourse()[0], newStudent.getDaysInCourse()[1], newStudent.getDaysInCourse()[2], newStudent.getDegreeSpecialty());
    }

  
    classRoster.printAll();
    std::cout << std::endl;

    classRoster.printInvalidEmails();
    std::cout << std::endl;

    classRoster.printByDegreeProgram(DegreeSpecialty::SOFTWARE);
    std::cout << std::endl;

    classRoster.remove("A3");
    std::cout << std::endl;

    classRoster.printAll();
    std::cout << std::endl;

    classRoster.remove("A3");
    std::cout << std::endl;

    */






    return 0;

}



 


/*These were incremental test to ensure every component of the program would work. Refer back to these if needed at any point. Many of the test have been removed to avoid confusion.

/ Create a student instance

    Student student("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, DegreeSpecialty::SECURITY);

 // TEST Print the student information using the getters
    std::cout << "Student ID: " << student.getId() << std::endl;
    std::cout << "First name: " << student.getFirstName() << std::endl;
    std::cout << "Last name: " << student.getLastName() << std::endl;
    std::cout << "Email: " << student.getEmail() << std::endl;
    std::cout << "Age: " << student.getAge() << std::endl;
    int* daysInCourse = student.getDaysInCourse();
    std::cout << "Days in course 1: " << daysInCourse[0] << std::endl;
    std::cout << "Days in course 2: " << daysInCourse[1] << std::endl;
    std::cout << "Days in course 3: " << daysInCourse[2] << std::endl;
    std::cout << "Degree specialty: " << static_cast<int>(student.getDegreeSpecialty()) << std::endl;
// TEST Update the student information using the setters
    student.setId("A2");
    student.setFirstName("Suzan");
    student.setLastName("Erickson");
    student.setEmail("Erickson_1990@gmail.com");
    student.setAge(19);
    student.setDaysInCourse(50, 30, 40);
    student.setDegreeSpecialty(DegreeSpecialty::NETWORK);
 // TEST Print the updated student information
    std::cout << "\nUpdated student information:" << std::endl;
    std::cout << "Student ID: " << student.getId() << std::endl;
    std::cout << "First name: " << student.getFirstName() << std::endl;
    std::cout << "Last name: " << student.getLastName() << std::endl;
    std::cout << "Email: " << student.getEmail() << std::endl;
    std::cout << "Age: " << student.getAge() << std::endl;
    daysInCourse = student.getDaysInCourse();
    std::cout << "Days in course 1: " << daysInCourse[0] << std::endl;
    std::cout << "Days in course 2: " << daysInCourse[1] << std::endl;
    std::cout << "Days in course 3: " << daysInCourse[2] << std::endl;
    std::cout << "Degree specialty: " << static_cast<int>(student.getDegreeSpecialty()) << std::endl;
    // TEST Add a student to the roster
    roster.add("A1", "John", "Doe", "john@email.com", 20, 90, 80, 70, DegreeSpecialty::SECURITY); // Add a student to the roster
    roster.add("A2", "Jane", "Doe", "jane@email.com", 21, 80, 70, 60, DegreeSpecialty::NETWORK); // Add a student to the roster
    roster.add("A3", "Bob", "Smith", "bob@email.com", 22, 70, 60, 50, DegreeSpecialty::SOFTWARE); // Add a student to the roster

    // Print all students in the roster
    for (int i = 0; i < 5; i++)
    {
        if (roster.classRosterArray[i] != nullptr)
        {
            roster.classRosterArray[i]->print();
        }
    }
//This will print the information for all the students in the classRosterArray
    roster.printAll();

    // Remove the student from the roster
    roster.remove("A1");


    // Call the print function on the student object
    student.print();


  // Print the average number of days in the three courses for the student with student ID "A1"
    roster.printAverageDaysInCourse("A1");
    roster.printAverageDaysInCourse("A2");
    roster.printAverageDaysInCourse("A3");
    std::cout << "suceesss";

    Roster.cpp test 
    // Destructor
Roster::~Roster()
{
    // Delete all student objects from the array
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            std::cout << "Deleting student " << i << std::endl;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}












*/