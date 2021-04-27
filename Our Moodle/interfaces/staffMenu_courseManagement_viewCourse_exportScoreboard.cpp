#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement_viewCourse_exportScoreboard() {
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    Course course = getCurrentCourse();
    string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + codeOfCourse(course) + ".csv";

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t     ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " EXPORT SCOREBOARD "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\tScoreboard will be exported to \"" << path << "\" \n\n";
    cout << "\t\t\t\t\t      Action(commit/back): \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    do {
        string confirm; gotoxy(67, 14); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                exportCourse(semester, course);
                cout << "\n\t\t\t\t\tCourse has been exported successfully";
                delay(1500); return;
            }
        gotoxy(67, 14); for (char c : confirm) cout << ' ';
    } while (true);

    goto reenter;
}