#include "../models/courseManagementSystem.h"

void studentMenu_viewProfile() {
    User account;
    getCurrentAccount(account);

    string className = account.Class;
    Vector<Student> students;
    getStudents(className, students);
    int n = students.current;

    Student student = students.find([account](Student student) -> bool {return student.id == account.username; });
   
reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t   ";

    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " " << student.lastName << " " << student.firstName << " "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    gotoxy(55, 10 + 2); cout << "Student ID: " << student.id;
    gotoxy(55, 10 + 4); cout << "First name: " << student.firstName;
    gotoxy(55, 10 + 6); cout << "Last name: " << student.lastName;
    gotoxy(55, 10 + 8); cout << "Gender: " << student.gender;
    gotoxy(55, 10 + 10); cout << "Date of Birth: ";  printf("%02d/%02d/%04d", student.dob.day, student.dob.month, student.dob.year);
    gotoxy(55, 10 + 12); cout << "Social ID: " << student.socialId;
    cout << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tType \"back\" to return: ";
    string action; read(action);
    if (action == "back") return;

    goto reenter;
}