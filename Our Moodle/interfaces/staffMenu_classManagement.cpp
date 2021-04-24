#include "../models/courseManagementSystem.h"

void staffMenu_classManagement() {
    int choice;
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CLASS MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t      1. Create classes\n\n";
    cout << "\t\t\t\t\t      2. Choose a class to manage\n\n";
    cout << "\t\t\t\t\t      3. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1: staffMenu_classManagement_createClass(); break;
    case 2: staffMenu_classManagement_viewClass(); break;
    case 3: return;
    default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1500);
    }

    goto reenter;
}