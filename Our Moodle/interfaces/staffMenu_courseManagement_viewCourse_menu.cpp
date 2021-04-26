#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement_viewCourse_menu() {

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " COURSE MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t 1. View students\n\n";
    cout << "\t\t\t\t\t\t 2. Export scoreboard\n\n";
    cout << "\t\t\t\t\t\t 3. Import scoreboard\n\n";
    cout << "\t\t\t\t\t\t 4. View scoreboard\n\n";
    cout << "\t\t\t\t\t\t 5. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\t Enter Your Choice : ";
    int choice; if (!readInt(choice) || choice < 1 || 5 < choice) {
        cout << "\n\t\t\t\t\t\t    Invalid choice";
        delay(1500);
    }
    else {
        switch (choice) {
        case 1: staffMenu_courseManagement_viewCourse_viewStudent(); break;
        case 2: staffMenu_courseManagement_viewCourse_exportScoreboard(); break;
        case 3: staffMenu_courseManagement_viewCourse_importScoreboard(); break;
        case 4: staffMenu_courseManagement_viewCourse_viewScoreboard(); break;
        case 5: return;
        }
    }

    goto reenter;
}