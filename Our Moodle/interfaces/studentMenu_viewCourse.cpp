#include "../models/courseManagementSystem.h"

void studentMenu_viewCourse() {
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    User account; getCurrentAccount(account);

    Vector<string> courseList;
    getStudentCourseList(year, term, account.username, courseList);
    Vector<Course> courses;
    getCourses(courseList, courses);
    int n = courses.current;

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t       ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " ENROLLED COURSE "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    gotoxy(2, 12); cout << "No";
    gotoxy(6, 12); cout << " Course ID";
    gotoxy(6, 13); cout << " ";
    gotoxy(17, 12); cout << " Course name";
    gotoxy(17, 13); cout << " ";
    gotoxy(54, 12); cout << " Instructor";
    gotoxy(54, 13); cout << " ";
    gotoxy(77, 12); cout << " Number of";
    gotoxy(77, 13); cout << " credits";
    gotoxy(89, 12); cout << " Maximum";
    gotoxy(89, 13); cout << " student";
    gotoxy(99, 12); cout << " First";
    gotoxy(99, 13); cout << " session";
    gotoxy(109, 12); cout << " Second";
    gotoxy(109, 13); cout << " session";
    for (int i = 0; i < n; ++i) {
        gotoxy(2, 15 + i * 2); cout << i + 1 << ". ";
        gotoxy(6 + 1, 15 + i * 2); cout << courses[i].id;
        gotoxy(17 + 1, 15 + i * 2); cout << courses[i].name;
        gotoxy(54 + 1, 15 + i * 2); cout << courses[i].teacher;
        gotoxy(77 + 1, 15 + i * 2); cout << courses[i].nCredits;
        gotoxy(89 + 1, 15 + i * 2); cout << courses[i].maxCapacity;
        gotoxy(99 + 1, 15 + i * 2); cout << courses[i].day1 << '-' << courses[i].ses1;
        gotoxy(109 + 1, 15 + i * 2); cout << courses[i].day2 << '-' << courses[i].ses2;
    }
    cout << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tType \"back\" to return: ";
    string action; read(action);
    if (action == "back") return;

    goto reenter;
}