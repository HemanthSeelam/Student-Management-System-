#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    string grade;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Grade: ";
    getline(cin, s.grade);
    file << s.roll << "," << s.name << "," << s.age << "," << s.grade << endl;
    file.close();
    cout << "Student added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    string line;
    cout << "\n--- Student Records ---\n";
    while (getline(file, line)) cout << line << endl;
    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    string line;
    int roll;
    bool found = false;
    cout << "Enter Roll No to search: ";
    cin >> roll;
    while (getline(file, line)) {
        if (stoi(line.substr(0, line.find(','))) == roll) {
            cout << "Record Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "No record found.\n";
    file.close();
}

void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string line;
    int roll;
    bool found = false;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    while (getline(file, line)) {
        if (stoi(line.substr(0, line.find(','))) != roll)
            temp << line << endl;
        else found = true;
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) cout << "Record deleted successfully!\n";
    else cout << "No record found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
