#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    void input() {
        cout << "Enter Name, Roll, Marks: ";
        cin >> name >> roll >> marks;
    }

    void display() {
        cout << "\nName: " << name << " Roll: " << roll << " Marks: " << marks << endl;
    }
};

void addStudent() {
    Student s;
    s.input();
    ofstream fout("students.txt", ios::app);
    fout << s.name << " " << s.roll << " " << s.marks << endl;
    fout.close();
}

void viewStudents() {
    Student s;
    ifstream fin("students.txt");
    while (fin >> s.name >> s.roll >> s.marks)
        s.display();
    fin.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View All\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
    } while (choice != 3);
}
