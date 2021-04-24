#include "../models/courseManagementSystem.h"

void staffMenu()
{
    int choice;
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " FACULTY MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t 1. Create school year\n\n";
    cout << "\t\t\t\t\t\t 2. Create semester\n\n";
    cout << "\t\t\t\t\t\t 3. Course management\n\n";
    cout << "\t\t\t\t\t\t 4. Class management\n\n";
    cout << "\t\t\t\t\t\t 5. Student management\n\n";
    cout << "\t\t\t\t\t\t 6. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1: staffMenu_createSchoolYear(); break;
    case 2: staffMenu_createSemester(); break;
    case 3: staffMenu_courseManagement(); break;
    case 4: staffMenu_classManagement(); break;
    case 5: staffMenu_studentManagement(); break;
    case 6: return;
    default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1500);
    }

    goto reenter;
}