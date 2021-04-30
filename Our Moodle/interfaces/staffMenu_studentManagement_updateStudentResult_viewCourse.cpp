#include "../models/courseManagementSystem.h"

void staffMenu_studentManagement_updateStudentResult_viewCourse(string className, string student) {
reenter:
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;

    Vector<string> courseList;
    Vector<Mark> marks;
    getStudentScoreboard(year, term, student, courseList, marks);

    Vector<Course> Courses;
    getCourses(courseList, Courses);
    int n = marks.current;

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

    int No; Mark mark;
    cout << "\n\t\t\t\t\tChoose course number(choose 0 to return): ";
    if (!readInt(No) || No < 0 || n < No) goto error; if (No == 0) return;
    cout << "\t\t\t\t\t\tTotal mark: "; if (!readFloat(mark.totalMark)) goto error;
    cout << "\t\t\t\t\t\tFinal mark: "; if (!readFloat(mark.finalMark)) goto error;
    cout << "\t\t\t\t\t\tMidterm mark: "; if (!readFloat(mark.midtermMark)) goto error;
    cout << "\t\t\t\t\t\tOther mark: "; if (!readFloat(mark.otherMark)) goto error;
    
    addStudentMark(year, term, student, codeOfCourse(Courses[No - 1]), mark);
    updateCourseMark(year, term, codeOfCourse(Courses[No - 1]), student, mark);
    updateStudentMark(student, className, marks[No - 1].totalMark, mark.totalMark);

    cout << "\n\t\t\t\t\t     Result has been updated successfully";
    delay(1500);
    

    goto reenter;

error:
    cout << "\n\t\t\t\t\t\tInvalid choice";
    delay(1500);
    goto reenter;
}