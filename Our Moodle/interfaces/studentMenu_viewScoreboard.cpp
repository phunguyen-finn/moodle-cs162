#include "../models/courseManagementSystem.h"

void studentMenu_viewScoreboard() {
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    User account; 
    getCurrentAccount(account);

    Vector<string> courseList;
    Vector<Mark> marks;
    getStudentScoreboard(year, term, account.username, courseList, marks);

    Vector<Course> Courses;
    getCourses(courseList, Courses);
    int n = marks.current;

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " Scoreboard "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    int based = 5; cout.precision(2);
    gotoxy(10 + based, 12); cout << "No";
    gotoxy(15 + based, 12); cout << "Course ID";
    gotoxy(27 + based, 12); cout << "Course name";
    gotoxy(67 + based, 12); cout << "Total";
    gotoxy(77 + based, 12); cout << "Final";
    gotoxy(87 + based, 12); cout << "Midterm";
    gotoxy(97 + based, 12); cout << "Other";
    for (int i = 0; i < n; ++i) {
        gotoxy(10 + based, 14 + i * 2); cout << i + 1 << ". ";
        gotoxy(15 + based, 14 + i * 2); cout << Courses[i].id;
        gotoxy(27 + based, 14 + i * 2); cout << Courses[i].name;
        gotoxy(67 + based, 14 + i * 2); cout << fixed << marks[i].totalMark;
        gotoxy(77 + based, 14 + i * 2); cout << fixed << marks[i].finalMark;
        gotoxy(87 + based, 14 + i * 2); cout << fixed << marks[i].midtermMark;
        gotoxy(97 + based, 14 + i * 2); cout << fixed << marks[i].otherMark;
    }
    cout << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tType \"back\" to return: ";
    string action; read(action);
    if (action == "back") return;

    goto reenter;
}