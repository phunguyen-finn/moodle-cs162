#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void gotoxy(int x, int y);
void delay(unsigned int mseconds);

void set_console_size();
void Loading();


bool adminLogin(string username, string password);
bool studentLogin(string username, string password);
void Heading();

void LoginWindow();
    void studentMenu();
        void studentMenu_addCourse();
        void studentMenu_removeCourse();
        void studentMenu_viewCourse();
        void studentMenu_viewScoreboard();
    void staffMenu();
        void staffMenu_createSchoolYear();
        void staffMenu_createSemester();
        void staffMenu_courseManagement();
            void staffMenu_courseManagement_createRegistration();
            void staffMenu_courseManagement_addCourse();
            void staffMenu_courseManagement_updateCourse();
            void staffMenu_courseManagement_deleteCourse();
            void staffMenu_courseManagement_viewCourse();
                void staffMenu_courseManagement_viewCourse_viewStudent();
                void staffMenu_courseManagement_viewCourse_exportScoreboard();
                void staffMenu_courseManagement_viewCourse_importScoreboard();
                void staffMenu_courseManagement_viewCourse_viewScoreboard();
        void staffMenu_classManagement();
            void staffMenu_classManagement_createClass();
            void staffMenu_classManagement_viewClass();
                void staffMenu_classManagement_viewClass_addStudent();
                void staffMenu_classManagement_viewClass_viewStudent();
                void staffMenu_classManagement_viewClass_viewScoreboard();
        void staffMenu_studentManagement();
            void staffMenu_studentManagement_updateStudentResult();

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void set_console_size()
{
    HANDLE hOut;
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    //set x and y to whatever ye' want
    int x = 125; // 125
    int y = 55; // 55

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     DisplayArea.Right  = x;
     DisplayArea.Bottom = y;

     SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}
void Loading(void)
{
    cout << "\n\n\n\n\n\n";
    cout << "\n\n\n\t\t\t\t\t\tCOURSE MANAGEMENT SYSTEM";
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t\t\t";
    cout << "Loading...\n";

    cout << "\n"; for (int rep = 1; rep <= 120; rep++) cout << "_"; cout << endl;
    cout << "\n\n"; for (int rep = 1; rep <= 120; rep++) cout << "_"; cout << endl << endl;

    gotoxy(0, 15);

    cout << "\n\n\n\n\n  ";
    for (int rep = 1; rep <= 5; rep++) { cout << char(219); delay(60); }
    for (int rep = 1; rep <= 10; rep++) { cout << char(219); delay(50); }
    for (int rep = 1; rep <= 25; rep++) { cout << char(219); delay(40); }
    for (int rep = 1; rep <= 76; rep++) { cout << char(219); delay(15); }


    delay(700);

    system("CLS");
    Beep(700, 100);
}
void LoginWindow()
{
    string username, password;
    reenter: 
    system("CLS"); 
    username = "";
    password = "";

    cout << "\n\n\n\n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
    cout << "\n";
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; cout << " " << char(220); for (int i = 1; i <= 8; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << char(220); for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << char(220); for (int i = 1; i <= 6; i++)cout << " "; cout << char(220); for (int i = 1; i <= 8; i++)cout << char(219); cout << "\t\t\t             COURSE MANAGEMENT SYSTEM";
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << " "; cout << char(220); for (int i = 1; i <= 2; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << char(223); for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << char(223); for (int i = 1; i <= 2; i++)cout << char(219); cout << char(220); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219);
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(223) << " " << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " ";/**/cout << char(219) << char(223) << " ";
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << "\t\t\t\t          VIETNAM NATIONAL UNIVERSITY";
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 4; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); cout << " " << char(223); for (int i = 1; i <= 11; i++)cout << char(219);
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(220) << " " << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); cout << "\t\t\t\t\t     HO CHI MINH CITY";
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 4; i++)cout << " "; cout << char(219) << char(219) << char(219) << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; cout << " " << char(220) << char(219); for (int i = 1; i <= 3; i++)cout << " ";/**/cout << char(219) << char(219) << char(219);
    cout << "\n\t"; for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 8; i++)cout << char(219); cout << char(223); for (int i = 1; i <= 3; i++)cout << " "; cout << char(223) << char(219); for (int i = 1; i <= 3; i++)cout << " "; for (int i = 1; i <= 3; i++)cout << char(219); for (int i = 1; i <= 3; i++)cout << " "; cout << char(219) << char(223); for (int i = 1; i <= 3; i++)cout << " "; cout << char(220); for (int i = 1; i <= 8; i++)cout << char(219); cout << char(223); cout << "\t\t\t\t\tUNIVERSITY OF SCIENCE";
    cout << "\n\n\n"; for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 9; rep++) cout << char(219); cout << " LOGIN "; for (int rep = 1; rep <= 9; rep++) cout << char(219);
    cout << "\n\n\t\t\t\t\t\t"; cout << "Username : "; 
    cout << "\n\n\t\t\t\t\t\t"; cout << "Password : "; 

    gotoxy(59, 25); fflush(stdin); getline(cin, username);
    gotoxy(59, 27); char character; 
    while (character = getch(), character != 13) 
    if (character == '\b') {
        // y = 27, x = 59
        if (password.size() == 0) continue;
        password.pop_back();
        gotoxy(59 + password.size(), 27); cout << ' ';
        gotoxy(59 + password.size(), 27);
    } 
    else {    
        password += character;
        cout << "*";
    }
    cout << endl;
    // cout << username <<' ' << password << endl;

    if (adminLogin(username, password)) staffMenu(); else 
    if (studentLogin(username, password)) studentMenu(); else {
        cout << "\t\t\t\t\t\t"; cout << "Unsuccessful login attemp";
        delay(1000); 
    }
    goto reenter; 
}
bool adminLogin(string username, string password) {
    return username == "admin" && password == "admin";
}
bool studentLogin(string username, string password) {
    return username == "student" && password == "student";
}

void Heading()
{
    cout << "\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
    cout << "\n\n\t\t\t\t\t\tCOURSE MANAGEMENT SYSTEM \t\t\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
}
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
    cout << "\t\t\t\t\t\t   5. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice; 
    switch (choice) {
        case 1: studentMenu_addCourse(); break;
        case 2: studentMenu_removeCourse(); break;
        case 3: studentMenu_viewCourse(); break;
        case 4: studentMenu_viewScoreboard(); break;
        case 5: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }
    
    goto reenter;
}
void staffMenu()
{
    int choice; 
    reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " FACULTY MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t 1. Create school year\n\n";
    cout << "\t\t\t\t\t\t 2. Create semester\n\n";
    cout << "\t\t\t\t\t\t 3. Course management\n\n";
    cout << "\t\t\t\t\t\t 4. Class management\n\n";
    cout << "\t\t\t\t\t\t 5. Student management\n\n";
    cout << "\t\t\t\t\t\t 6. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1: staffMenu_createSchoolYear(); break;
        case 2: staffMenu_createSemester(); break;
        case 3: staffMenu_courseManagement(); break;
        case 4: staffMenu_classManagement(); break;
        case 5: staffMenu_studentManagement(); break;
        case 6: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }

    goto reenter;
}
void staffMenu_courseManagement() {
    int choice; 
    reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " COURSE MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t     1. Create course registration\n\n";
    cout << "\t\t\t\t\t     2. Add a course\n\n";
    cout << "\t\t\t\t\t     3. Update a course\n\n";
    cout << "\t\t\t\t\t     4. Delete a course\n\n";
    cout << "\t\t\t\t\t     5. Choose a course to manage\n\n";
    cout << "\t\t\t\t\t     6. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1: staffMenu_courseManagement_createRegistration(); break;
        case 2: staffMenu_courseManagement_addCourse(); break;
        case 3: staffMenu_courseManagement_updateCourse(); break;
        case 4: staffMenu_courseManagement_deleteCourse(); break;
        case 5: staffMenu_courseManagement_viewCourse(); break;
        case 6: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }

    goto reenter;
}
void staffMenu_classManagement() {
    int choice; 
    reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CLASS MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t      1. Create classes\n\n";
    cout << "\t\t\t\t\t      2. Choose a class to manage\n\n";
    cout << "\t\t\t\t\t      3. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1: staffMenu_classManagement_createClass(); break;
        case 2: staffMenu_classManagement_viewClass(); break;
        case 3: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }

    goto reenter;
}
void staffMenu_studentManagement() {
    int choice; 
    reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t\t";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " STUDENT MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t1. Update student result\n\n";
    cout << "\t\t\t\t\t\t2. Go back\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1: staffMenu_studentManagement_updateStudentResult(); break;
        case 2: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }

    goto reenter;
}
void staffMenu_courseManagement_viewCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_classManagement_viewClass() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}

void studentMenu_addCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void studentMenu_removeCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void studentMenu_viewCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void studentMenu_viewScoreboard() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_createSchoolYear() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_createSemester() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_createRegistration() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_addCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_updateCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_deleteCourse() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_viewCourse_viewStudent() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_viewCourse_exportScoreboard() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_viewCourse_importScoreboard() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_courseManagement_viewCourse_viewScoreboard() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_classManagement_createClass() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_classManagement_viewClass_addStudent() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_classManagement_viewClass_viewStudent() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_classManagement_viewClass_viewScoreboard() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}
void staffMenu_studentManagement_updateStudentResult() {
    system("CLS");
    cout << "not complete";
    delay(1000);
}

#endif // !WINDOW_H
