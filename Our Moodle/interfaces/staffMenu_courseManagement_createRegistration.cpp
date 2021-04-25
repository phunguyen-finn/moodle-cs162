#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement_createRegistration() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t      ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CREATE COURSE REGISTRATION SESSION "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t    Start date(dd/mm/yyyy): \n\n";
    cout << "\t\t\t\t\t    End date(dd/mm/yyyy)  : \n\n";
    cout << "\t\t\t\t\t    Action(commit/back)   : \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    Date start, end;
    gotoxy(68, 12); if (!readDate(start)) goto error;
    gotoxy(68, 14); if (!readDate(end)) goto error;
    do {
        string confirm; gotoxy(68, 16); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                setCourseRegistration(start, end);
                cout << "\n\t\t\t\t Course registration session has been created successfully";
                delay(1500); return;
            }
        gotoxy(68, 16); for (char c : confirm) cout << ' ';
    } while (true);

error:
    gotoxy(54, 18); cout << "Invalid input";
    delay(1500);

    goto reenter;
}