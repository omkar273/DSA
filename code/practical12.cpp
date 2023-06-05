// Company maintains employee information as employee ID, name, designation and salary.Allow user to add, delete information of employee.Display information of particular employee.If employee does not exist an appropriate message is displayed.If it is, then the system displays the employee details.Use index sequential file to maintain the data.

#include <bits/stdc++.h>

using namespace std;

struct Employee {
    int employeeID;
    string name;
    string designation;
    float salary;
};

const string FILE_NAME = "employee_data.txt";

void addEmployee() {
    ofstream file(FILE_NAME, ios::app | ios::binary);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Employee employee;
    cout << "Enter employee ID: ";
    cin >> employee.employeeID;
    cin.ignore();  // Ignore newline character
    cout << "Enter employee name: ";
    getline(cin, employee.name);
    cout << "Enter employee designation: ";
    getline(cin, employee.designation);
    cout << "Enter employee salary: ";
    cin >> employee.salary;

    file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
    file.close();

    cout << "Employee added successfully." << endl;
}

void deleteEmployee() {
    ifstream inFile(FILE_NAME, ios::binary);
    ofstream outFile("temp.txt", ios::binary);

    if (!inFile) {
        cout << "Error opening file." << endl;
        return;
    }

    int employeeID;
    cout << "Enter the employee ID to delete: ";
    cin >> employeeID;

    Employee employee;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.employeeID == employeeID) {
            found = true;
            continue;
        }
        outFile.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
    }

    inFile.close();
    outFile.close();

    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (found) {
        cout << "Employee deleted successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

void displayEmployee() {
    ifstream file(FILE_NAME, ios::binary);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    int employeeID;
    cout << "Enter the employee ID to display: ";
    cin >> employeeID;

    Employee employee;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.employeeID == employeeID) {
            found = true;
            cout << "Employee ID: " << employee.employeeID << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Designation: " << employee.designation << endl;
            cout << "Salary: " << employee.salary << endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Employee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
