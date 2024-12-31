#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Student class to structure student information
class Student {
public:
    string name;
    int rollNumber;
    char grade;
    int age;

    // Constructor to initialize student data
    Student(string name, int rollNumber, char grade, int age) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->grade = grade;
        this->age = age;
    }

    // Method to display the student's information
    void displayInformation() {
        cout << "\n--- Student Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Grade: " << grade << endl;
        cout << "Age: " << age << endl;
    }
};

// SchoolManagement class to manage the student information
class SchoolManagement {
private:
    vector<Student> students;

public:
    // Function to collect student information through the form
    void collectStudentInformation() {
        string name;
        int rollNumber;
        char grade;
        int age;

        // Displaying the form for user to input student information
        cout << "------ Student Information Form ------" << endl;

        cout << "Enter student's name: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter grade (A, B, C, etc.): ";
        cin >> grade;

        cout << "Enter age: ";
        cin >> age;

        // Create a Student object and store it
        Student newStudent(name, rollNumber, grade, age);
        students.push_back(newStudent);

        cout << "\nStudent information collected successfully!" << endl;
    }

    // Function to display all stored students' information
    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo student data available!" << endl;
            return;
        }

        cout << "\n--- All Student Information ---" << endl;
        for (const auto& student : students) {
            student.displayInformation();
            cout << "-------------------------------" << endl;
        }
    }
};

int main() {
    SchoolManagement sm;
    int choice;

    while (true) {
        // Menu to choose actions
        cout << "\nSchool Management System\n";
        cout << "1. Collect Student Information\n";
        cout << "2. Display All Student Information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sm.collectStudentInformation();
            break;
        case 2:
            sm.displayAllStudents();
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
