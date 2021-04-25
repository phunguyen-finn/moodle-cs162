#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_createClass() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t      ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CREATE CLASS "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t    Class name          : \n\n";
    cout << "\t\t\t\t\t    Action(commit/back) : \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    string className;
    gotoxy(66, 12); if (!read(className)) goto error;
    do {
        string confirm; gotoxy(66, 14); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                createClass(className);
                gotoxy(41, 16); cout << "Class has been created successfully";
                delay(1500); return;
            }
        gotoxy(66, 14); for (char c : confirm) cout << ' ';
    } while (true);

error:
    gotoxy(52, 16); cout << "Invalid input";
    delay(1500);
    
    goto reenter;
}