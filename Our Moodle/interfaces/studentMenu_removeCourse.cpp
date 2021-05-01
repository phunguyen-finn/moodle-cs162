#include "../models/courseManagementSystem.h"

void studentMenu_removeCourse() {
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t       ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CHOOSE A COURSE "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    Date start, end, current;
    getCourseRegistration(start, end);
    current = getCurrentDate();
    if (current < start || end < current) {
        gotoxy(41, 12); cout << "Course registration session isn't opened";
        delay(1500); return;
    }

reenter:
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    User account;
    getCurrentAccount(account);

    Vector<string> courseList;
    getStudentCourseList(year, term, account.username, courseList);
    Vector<Course> courses;
    getCourses(courseList, courses);
    int n = courses.current;

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

    cout << "\n\t\t\t\t\tChoose course number(choose 0 to return): ";
    int No; if (!readInt(No) || No < 0 || n < No) {
        cout << "\n\t\t\t\t\t\t\tInvalid choice";
        delay(1500);
    }
    else {
        if (No == 0) return;
        Vector<string> studentList, classList;
        getCourseStudentList(year, term, courses[No - 1], studentList, classList);
        studentRemoveCourse(year, term, account.username, codeOfCourse(courses[No - 1]), courseList, studentList, classList);

        cout << "\n\t\t\t\t\t   Course has been deleted successfully";
        delay(1500);
    }

    goto reenter;
}