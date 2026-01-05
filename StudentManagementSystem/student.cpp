#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "students.txt";

void addStudent() {
    ofstream file(FILENAME, ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    Student s;
    int n;

    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "How many grades? ";
    cin >> n;

    s.grades.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Grade " << i + 1 << ": ";
        cin >> s.grades[i];
    }

    file << s.id << "\n" << s.name << "\n" << n << "\n";
    for (int g : s.grades)
        file << g << " ";
    file << "\n";

    file.close();
    cout << "Student added successfully.\n";
}

void viewStudents() {
    ifstream file(FILENAME);
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    Student s;
    int n;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> n;

        s.grades.resize(n);
        for (int i = 0; i < n; i++)
            file >> s.grades[i];

        cout << "\nID: " << s.id;
        cout << "\nName: " << s.name;
        cout << "\nGrades: ";
        for (int g : s.grades)
            cout << g << " ";
        cout << "\n";
    }

    file.close();
}

void updateStudent() {
    ifstream file(FILENAME);
    ofstream temp("temp.txt");

    if (!file || !temp) {
        cout << "File error.\n";
        return;
    }

    int targetId;
    cout << "Enter ID to update: ";
    cin >> targetId;

    Student s;
    int n;
    bool found = false;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> n;

        s.grades.resize(n);
        for (int i = 0; i < n; i++)
            file >> s.grades[i];

        if (s.id == targetId) {
            found = true;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);

            cout << "How many new grades? ";
            cin >> n;
            s.grades.resize(n);
            for (int i = 0; i < n; i++) {
                cout << "Grade " << i + 1 << ": ";
                cin >> s.grades[i];
            }
        }

        temp << s.id << "\n" << s.name << "\n" << n << "\n";
        for (int g : s.grades)
            temp << g << " ";
        temp << "\n";
    }

    file.close();
    temp.close();

    remove(FILENAME.c_str());
    rename("temp.txt", FILENAME.c_str());

    if (found)
        cout << "Student updated.\n";
    else
        cout << "Student not found.\n";
}

void deleteStudent() {
    ifstream file(FILENAME);
    ofstream temp("temp.txt");

    if (!file || !temp) {
        cout << "File error.\n";
        return;
    }

    int targetId;
    cout << "Enter ID to delete: ";
    cin >> targetId;

    Student s;
    int n;
    bool found = false;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> n;

        s.grades.resize(n);
        for (int i = 0; i < n; i++)
            file >> s.grades[i];

        if (s.id == targetId) {
            found = true;
            continue; 
        }

        temp << s.id << "\n" << s.name << "\n" << n << "\n";
        for (int g : s.grades)
            temp << g << " ";
        temp << "\n";
    }

    file.close();
    temp.close();

    remove(FILENAME.c_str());
    rename("temp.txt", FILENAME.c_str());

    if (found)
        cout << "Student deleted.\n";
    else
        cout << "Student not found.\n";
}
