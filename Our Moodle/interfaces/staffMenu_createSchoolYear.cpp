#include "../models/courseManagementSystem.h"

void staffMenu_createSchoolYear() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t     ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CREATE SCHOOL YEAR "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t      Year(yyyy)         : \n\n";
    cout << "\t\t\t\t\t      Action(commit/back): \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    int year; gotoxy(67, 12); if (!readInt(year) || year<1000 || 9999<year) goto error;
    do {
        string confirm; gotoxy(67, 14); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                setCurrentYear(year);
                cout << "\n\t\t\t\t\t    Year has been created successfully";
                delay(1500); return;
            }
        gotoxy(67, 14); for (char c : confirm) cout << ' ';
    } while (true);
    
error:
    cout << "\n\n\n\t\t\t\t\t\t      Invalid input";
    delay(1500);

    goto reenter;
}