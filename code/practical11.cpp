// Department maintains a student information.The file contains roll number, name, division and address.Allow user to add, delete information of student.Display information of particular employee.If record of student does not exist an appropriate message is displayed.If it is, then the system displays the student details.Use sequential file to main the data.

#include <bits/stdc++.h>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() {
    ofstream file("student_data.txt", ios::app);
    if (!file) {
        cout << "Error opening file.";
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();
}

void deleteStudent() {
    ifstream file("student_data.txt");
    if (!file) {
        cout << "Error opening file.";
        return;
    }

    int rollNumber;
    cout << "Enter Roll Number of student to delete: ";
    cin >> rollNumber;

    string line;
    ofstream tempFile("temp.txt");
    bool found = false;
    while (getline(file, line)) {
        string roll, name, division, address;
        size_t pos = line.find(',');
        roll = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        division = line.substr(0, pos);
        line.erase(0, pos + 1);

        address = line;

        if (stoi(roll) != rollNumber) {
            tempFile << roll << "," << name << "," << division << "," << address << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("student_data.txt");
        rename("temp.txt", "student_data.txt");
        cout << "Student record deleted." << endl;
    } else {
        remove("temp.txt");
        cout << "Student record not found." << endl;
    }
}

void displayStudent() {
    ifstream file("student_data.txt");
    if (!file) {
        cout << "Error opening file.";
        return;
    }

    int rollNumber;
    cout << "Enter Roll Number of student to display: ";
    cin >> rollNumber;

    string line;
    bool found = false;
    while (getline(file, line)) {
        string roll, name, division, address;
        size_t pos = line.find(',');
        roll = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        division = line.substr(0, pos);
        line.erase(0, pos + 1);

        address = line;

        if (stoi(roll) == rollNumber) {
            found = true;
            cout << "Roll Number: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Division: " << division << endl;
            cout << "Address: " << address << endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
