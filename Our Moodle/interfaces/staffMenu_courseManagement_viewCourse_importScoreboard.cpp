#include "../models/courseManagementSystem.h"

void staffMenu_courseManagement_viewCourse_importScoreboard() {
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    Course course = getCurrentCourse();
    string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + codeOfCourse(course) + ".csv";

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t     ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " IMPORT SCOREBOARD "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\tScoreboard will be imported from \"" << path << "\" \n\n";
    cout << "\t\t\tMake sure you put the csv file in the right path\n\n";
    cout << "\t\t\t\t\t      Action(commit/back): \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    do {
        string confirm; gotoxy(67, 16); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                Vector<string> ids, fullnames;
                Vector<Mark> marks;
                importCourse(year, term, codeOfCourse(course), ids, fullnames, marks);

                updateCourseMark(year, term, codeOfCourse(course), ids, fullnames, marks);
                int n = marks.current;
                for (int i = 0; i < n; ++i) addStudentMark(year, term, ids[i], codeOfCourse(course), marks[i]);

                Vector<string> studentList, classList;
                getCourseStudentList(year, term, course, studentList, classList);
                for (int i = 0; i < n; ++i) addStudentMark(studentList[i], classList[i], marks[i].totalMark);

                cout << "\n\t\t\t\t\tCourse has been imported successfully";
                delay(1500); return;
            }
        gotoxy(67, 16); for (char c : confirm) cout << ' ';
    } while (true);

    goto reenter;
}