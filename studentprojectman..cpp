#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    float marks;
};

// Function to add a new student record
void addRecord() {
    ofstream outFile("student_records.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    Student newStudent;

    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore newline character
    getline(cin, newStudent.name);
    cout << "Enter Marks: ";
    cin >> newStudent.marks;

    outFile << newStudent.rollNumber << " " << newStudent.name << " " << newStudent.marks << endl;

    cout << "Record added successfully!" << endl;

    outFile.close();
}

// Function to display all student records
void displayRecords() {
    ifstream inFile("student_records.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    Student student;
    cout << "Roll Number\tName\t\tMarks" << endl;
    while (inFile >> student.rollNumber >> ws && getline(inFile, student.name) && inFile >> student.marks) {
        cout << student.rollNumber << "\t\t" << setw(15) << left << student.name << "\t" << student.marks << endl;
    }

    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Record\n2. Display Records\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
