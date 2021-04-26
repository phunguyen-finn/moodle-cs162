#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_viewClass_menu()
{
    string className = getCurrentClass();

reenter:
    system("CLS"); Heading(); 
    cout << "\n\n\t\t\t\t\t\t   ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " " << className << " "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t   1. Add students\n\n";
    cout << "\t\t\t\t\t\t   2. View students\n\n";
    cout << "\t\t\t\t\t\t   3. View scoreboard\n\n";
    cout << "\t\t\t\t\t\t   4. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    
    cout << "\n\t\t\t\t\t\t   Enter Your Choice : "; 
    int choice; if (!readInt(choice) || choice < 1 || 4 < choice) {
        cout << "\n\t\t\t\t\t\t    Invalid choice"; 
        delay(1500);
    }
    else {
        switch (choice) {
        case 1: staffMenu_classManagement_viewClass_addStudent(); break;
        case 2: staffMenu_classManagement_viewClass_viewStudent(); break;
        case 3: staffMenu_classManagement_viewClass_viewScoreboard(); break;
        case 4: return;
        }
    }
    
    goto reenter;
}