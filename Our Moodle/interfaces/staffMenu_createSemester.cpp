#include "../models/courseManagementSystem.h"

void staffMenu_createSemester() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t      ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CREATE SEMESTER "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t      Semester(1/2/3)       : \n\n";
    cout << "\t\t\t\t\t      Start date(dd/mm/yyyy): \n\n";
    cout << "\t\t\t\t\t      End date(dd/mm/yyyy)  : \n\n";
    cout << "\t\t\t\t\t      Action(commit/back)   : \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    int semester; Date start, end;
    gotoxy(70, 12); if (!readInt(semester) || semester<1 || 3<semester) goto error;
    gotoxy(70, 14); if (!readDate(start)) goto error;
    gotoxy(70, 16); if (!readDate(end)) goto error;
    do {
        string confirm; gotoxy(70, 18); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                setCurrentSemester(getCurrentYear(), semester, start, end);

                Vector<string> classList;
                getClasses(classList);
                int n = classList.current;
                for (int i = 0; i < n; ++i) {
                    Vector<string> studentList;
                    getStudentList(classList[i], studentList);
                    addStudentToSemester(studentList);
                }

                cout << "\n\t\t\t\t\t   Semester has been created successfully";
                delay(1500); return;
            }
        gotoxy(70, 18); for (char c : confirm) cout << ' ';
    } while (true);

error:
    gotoxy(53, 20); cout << "Invalid input";
    delay(1500);

    goto reenter;
}