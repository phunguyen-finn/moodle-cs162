#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement() {
    int choice;
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " COURSE MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t     1. Create course registration\n\n";
    cout << "\t\t\t\t\t     2. Add a course\n\n";
    cout << "\t\t\t\t\t     3. Update a course\n\n";
    cout << "\t\t\t\t\t     4. Delete a course\n\n";
    cout << "\t\t\t\t\t     5. Choose a course to manage\n\n";
    cout << "\t\t\t\t\t     6. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1: staffMenu_courseManagement_createRegistration(); break;
    case 2: staffMenu_courseManagement_addCourse(); break;
    case 3: staffMenu_courseManagement_updateCourse(); break;
    case 4: staffMenu_courseManagement_deleteCourse(); break;
    case 5: staffMenu_courseManagement_viewCourse(); break;
    case 6: return;
    default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1500);
    }

    goto reenter;
}