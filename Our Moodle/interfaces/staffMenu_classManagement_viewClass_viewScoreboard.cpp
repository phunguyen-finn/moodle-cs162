#include "../models/courseManagementSystem.h"

void staffMenu_classManagement_viewClass_viewScoreboard() {
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;

    string Class = getCurrentClass();
    Vector<Student> students;
    getStudents(Class, students);
    int n = students.current;

reenter:
    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " Scoreboard "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";

    cout.precision(2);
    for (int i = 0; i < n; ++i) {
        gotoxy(20, 14 + i * 3); cout << i + 1 << ". ";
        gotoxy(25, 14 + i * 3); cout << students[i].lastName + " " + students[i].firstName;
        gotoxy(25, 15 + i * 3); cout << students[i].id;

        Vector<string> courseList; 
        Vector<Mark> marks;
        Vector<Course> courses;
        getStudentScoreboard(year, term, students[i].id, courseList, marks);
        getCourses(courseList, courses);

        float sum = 0; int cnt = 0;
        for (int j = 0; j < 5; ++j)
            if (j < marks.current) {
                gotoxy(47 + j * 8, 14 + i * 3); cout << courses[j].id;
                gotoxy(47 + j * 8, 15 + i * 3); cout << fixed << marks[j].totalMark;
                sum += marks[j].totalMark;
                cnt += 1;
            }
            else {
                gotoxy(47 + j * 8, 14 + i * 3); cout << "----";
                gotoxy(47 + j * 8, 15 + i * 3); cout << "----";
            }
        float GPA = cnt > 0 ? sum / cnt : 0;

        gotoxy(87, 14 + i * 3); cout << "GPA";
        gotoxy(87, 15 + i * 3); cout << fixed << GPA / 10 * 4;

        gotoxy(95, 14 + i * 3); cout << "Overall GPA";
        gotoxy(95, 15 + i * 3); cout << fixed << getStudentGPA(students[i].id, Class);
    }
    cout << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    cout << "\n\t\t\t\t\t\tType \"back\" to return: ";
    string action; read(action);
    if (action == "back") return;

    goto reenter;
}