#include "../models/courseManagementSystem.h"

void staffMenu_createSchoolYear() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t     ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CREATE SCHOOL YEAR "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\tYear(yyyy): \n";
    cout << "\t\t\t\t\t\t(Type \'back\' to return)\n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    gotoxy(60, 12); string input; cin >> input;
    if (input == "back") return;
    if (isValidYear(input)) {
        setCurrentYear(input);
        gotoxy(48, 15); cout << "Year has been create successfully";
        delay(1500); return;
    }
    else {
        gotoxy(48, 15); cout << "Invalid year";
        delay(1500);
    }

    goto reenter;
}