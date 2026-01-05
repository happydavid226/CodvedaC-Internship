#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    std::vector<int> grades;
};
void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();

#endif
