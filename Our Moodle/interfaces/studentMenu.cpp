#include "../models/courseManagementSystem.h"

void studentMenu()
{
    int choice;
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " STUDENT MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t   1. Add a course\n\n";
    cout << "\t\t\t\t\t\t   2. Remove a course\n\n";
    cout << "\t\t\t\t\t\t   3. My courses\n\n";
    cout << "\t\t\t\t\t\t   4. My scoreboard\n\n";
    cout << "\t\t\t\t\t\t   5. Change password\n\n";
    cout << "\t\t\t\t\t\t   6. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    fflush(stdin);
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1: if (getCurrentSemester().term == 0) goto emptysemester;
            studentMenu_addCourse(); break;
    case 2: if (getCurrentSemester().term == 0) goto emptysemester;
            studentMenu_removeCourse(); break;
    case 3: if (getCurrentSemester().term == 0) goto emptysemester;
            studentMenu_viewCourse(); break;
    case 4: if (getCurrentSemester().term == 0) goto emptysemester;
            studentMenu_viewScoreboard(); break;
    case 5: changePasswordWindow(); break;
    case 6: return;
    default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1500);
    }

    goto reenter;

emptysemester:
    cout << "\n\t\t\t\t\t\tSemester hasn't been created!";
    delay(1500);
    goto reenter;
}