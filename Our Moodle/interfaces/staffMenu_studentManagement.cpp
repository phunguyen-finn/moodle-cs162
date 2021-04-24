#include "../models/courseManagementSystem.h"

void staffMenu_studentManagement() {
    int choice;
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " STUDENT MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t1. Update student result\n\n";
    cout << "\t\t\t\t\t\t2. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1: staffMenu_studentManagement_updateStudentResult(); break;
    case 2: return;
    default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1500);
    }

    goto reenter;
}