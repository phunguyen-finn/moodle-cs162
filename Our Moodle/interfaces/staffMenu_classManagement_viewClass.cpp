#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_viewClass() {
    Vector<string> Classes;
    getClasses(Classes);
    int n = Classes.current;

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t       "; 
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CHOOSE A CLASS "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    for (int i = 0; i < n; ++i) 
        cout << "\t\t\t\t\t\t     " << i + 1 << ". " << Classes[i] << "\n\n";
    cout << "\t\t\t\t\t\t     " << n + 1 << ". Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tChoose class number: ";
    int No; if (!readInt(No) || No < 1 || n+1 < No) {
        cout << "\n\t\t\t\t\t\tInvalid choice";
        delay(1500);
    }
    else {
        if (No == n + 1) return;
        setCurrentClass(Classes[No-1]);
        staffMenu_classManagement_viewClass_menu();
    }


    goto reenter;
}