#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_viewClass_viewStudent() {
    string className = getCurrentClass();
    Vector<Student> students;
    getStudents(className, students);
    int n = students.current;

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t   ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " " << className << " "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    gotoxy(10, 12); cout << "No";
    gotoxy(15, 12); cout << "Student ID";
    gotoxy(30, 12); cout << "First name";
    gotoxy(50, 12); cout << "Last name";
    gotoxy(70, 12); cout << "Gender";
    gotoxy(80, 12); cout << "Date of birth";
    gotoxy(100, 12); cout << "Social ID";
    for (int i = 0; i < n; ++i) {
        gotoxy(10, 14 + i * 2); cout << i + 1 << ". ";
        gotoxy(15, 14 + i * 2); cout << students[i].id;
        gotoxy(30, 14 + i * 2); cout << students[i].firstName;
        gotoxy(50, 14 + i * 2); cout << students[i].lastName;
        gotoxy(70, 14 + i * 2); cout << students[i].gender;
        gotoxy(80, 14 + i * 2); printf("%02d/%02d/%04d", students[i].dob.day, students[i].dob.month, students[i].dob.year);
        gotoxy(100, 14 + i * 2); cout << students[i].socialId;
    }
    cout << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tType \"back\" to return: "; 
    string action; read(action);
    if (action == "back") return;

    goto reenter;
}