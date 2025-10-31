#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student s;
    cout << "Enter ID, Name, Marks: ";
    cin >> s.id >> s.name >> s.marks;
    file << s.id << " " << s.name << " " << s.marks << "\n";
    file.close();
}

void viewStudents() {
    ifstream file("students.txt");
    Student s;
    cout << "\n--- Student Records ---\n";
    while (file >> s.id >> s.name >> s.marks)
        cout << s.id << " " << s.name << " " << s.marks << "\n";
    file.close();
}

int main() {
    int ch;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) addStudent();
        else if (ch == 2) viewStudents();
    } while (ch != 3);
}
