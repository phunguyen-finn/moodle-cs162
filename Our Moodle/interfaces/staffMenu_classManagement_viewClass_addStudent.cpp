#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_viewClass_addStudent() {
    string className = getCurrentClass();

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t   ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " " << className << " "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\tStudents will be imported from \"csvFile/classes/" + className + ".csv\" \n\n";
    cout << "\t\t\t\tMake sure you put the csv file in the right path\n\n";
    cout << "\t\t\t\t\t\tAction(commit/back): \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    do {
        string confirm; gotoxy(69, 16); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                Vector<string> studentList;
                addStudents(className, studentList);
                addStudentToSemester(studentList);

                cout << "\n\t\t\t\t\tStudents have been added successfully";
                delay(1500); return;
            }
        gotoxy(69, 16); for (char c : confirm) cout << ' ';
    } while (true);

    goto reenter;
}