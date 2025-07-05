#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float grade;
};

// Global student vector
vector<Student> students;

// Function to load students from file
void loadFromFile(const string &filename) {
    ifstream infile(filename);
    Student temp;
    while (infile >> temp.rollNumber >> temp.name >> temp.grade) {
        students.push_back(temp);
    }
    infile.close();
}

// Function to save students to file
void saveToFile(const string &filename) {
    ofstream outfile(filename);
    for (const auto &s : students) {
        outfile << s.rollNumber << " " << s.name << " " << s.grade << endl;
    }
    outfile.close();
}

// Function to add a student
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Grade: ";
    cin >> s.grade;

    students.push_back(s);
    cout << "Student added successfully.\n";
}

// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (const auto &s : students) {
        cout << "Roll Number: " << s.rollNumber << "\n";
        cout << "Name       : " << s.name << "\n";
        cout << "Grade      : " << s.grade << "\n";
        cout << "--------------------------\n";
    }
}

// Function to delete a student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == roll) {
            students.erase(it);
            cout << "Student record deleted.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with roll number " << roll << " not found.\n";
    }
}

int main(){
	
	const string filename = "student_records.txt";
    loadFromFile(filename);

    int choice;
    do {
        cout << "\n===== Student Record System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                saveToFile(filename);
                cout << "Exiting and saving records...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
	
	return 0;
}