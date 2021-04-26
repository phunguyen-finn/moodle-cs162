#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement_addCourse() {
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t  ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " ENTER A COURSE "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t      Course ID: \n\n";
    cout << "\t\t\t\t      Couse name: \n\n";
    cout << "\t\t\t\t      Instructor: \n\n";
    cout << "\t\t\t\t      Number of credits: \n\n";
    cout << "\t\t\t\t      Maximum student: \n\n";
    cout << "\t\t\t\t      First day of week(MON/TUE/WED/THU/FRI/SAT): \n\n";
    cout << "\t\t\t\t      First session of week(S1/S2/S3/S4): \n\n";
    cout << "\t\t\t\t      Second day of week(MON/TUE/WED/THU/FRI/SAT): \n\n";
    cout << "\t\t\t\t      Second session of week(S1/S2/S3/S4): \n\n";
    cout << "\t\t\t\t      Action(commit/back): \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    string id, name, instructor;
    int nCredits, maxStudent;
    string day1, ses1, day2, ses2;

    gotoxy(49, 12); if (!read(id)) goto error; cin.ignore();
    gotoxy(50, 14); if (!readLine(name)) goto error; 
    gotoxy(50, 16); if (!readLine(instructor)) goto error;
    gotoxy(57, 18); if (!readInt(nCredits)) goto error;
    gotoxy(55, 20); if (!readInt(maxStudent)) goto error;
    gotoxy(82, 22); if (!read(day1)) goto error;
    gotoxy(74, 24); if (!read(ses1)) goto error;
    gotoxy(83, 26); if (!read(day2)) goto error;
    gotoxy(75, 28); if (!read(ses2)) goto error;

    do {
        string action; gotoxy(59, 30); read(action);
        if (action == "back") return; else
            if (action == "commit") {
                addCourse(Course(id, name, instructor, nCredits, maxStudent, day1, ses1, day2, ses2));
                cout << "\n\t\t\t\t\t     Course has been added successfully";
                delay(1500); return;
            }
        gotoxy(70, 18); for (char c : action) cout << ' ';
    } while (true);

error:
    gotoxy(55, 32); cout << "Invalid input";
    delay(1500);

    goto reenter;
}