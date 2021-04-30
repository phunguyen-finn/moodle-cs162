#include "../models/courseManagementSystem.h"

void staffMenu_studentManagement_updateStudentResult() {
reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t      ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " UPDATE RESULT "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t    Class name          : \n\n";
    cout << "\t\t\t\t\t    Student ID          : \n\n";
    cout << "\t\t\t\t\t    Action(commit/back) : \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    string className, student;
    gotoxy(66, 12); if (!read(className)) goto error;
    gotoxy(66, 14); if (!read(student)) goto error;
    do {
        string confirm; gotoxy(66, 16); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                staffMenu_studentManagement_updateStudentResult_viewCourse(className, student);
                return;
            }
        gotoxy(66, 16); for (char c : confirm) cout << ' ';
    } while (true);

error:
    gotoxy(52, 18); cout << "Invalid input";
    delay(1500);

    goto reenter;
}