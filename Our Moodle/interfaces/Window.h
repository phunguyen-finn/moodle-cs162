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
    void Student_Menu();
        void Student_Add_Course();
        void Student_Remove_Course();
        void Student_View_Courses();
        void Student_View_Scoreboard();
    void Faculty_Menu();
        void Create_School_Year();
        void Create_Semester();
        void Course_Management();
        void Class_Management();
        void Student_Management();


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

    if (adminLogin(username, password)) Faculty_Menu(); else 
    if (studentLogin(username, password)) Student_Menu(); else {
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
void Student_Menu()
{
    int choice; 
    reenter: 

    system("CLS"); Heading();
	cout << "\n\n\t\t\t\t\t\t";
	for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " STUDENT MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
	cout << "\n\n";
	cout << "\t\t\t\t\t\t    1. Add a course\n\n";
	cout << "\t\t\t\t\t\t    2. Remove a course\n\n";
    cout << "\t\t\t\t\t\t    3. My courses\n\n";
	cout << "\t\t\t\t\t\t    4. My scoreboard\n\n";
	cout << "\t\t\t\t\t\t    5. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice; 
    switch (choice) {
        case 1: Student_Add_Course(); break;
        case 2: Student_Remove_Course(); break;
        case 3: Student_View_Courses(); break;
        case 4: Student_View_Scoreboard(); break;
        case 5: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }
    
    goto reenter;
}
void Faculty_Menu()
{
    int choice; 
    reenter:

	system("CLS"); Heading();
	cout << "\n\n\t\t\t\t\t\t";
	for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " FACULTY MENU "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
	cout << "\n\n";
	cout << "\t\t\t\t\t\t  1. Create school year\n\n";
	cout << "\t\t\t\t\t\t  2. Create semester\n\n";
    cout << "\t\t\t\t\t\t  3. Course management\n\n";
    cout << "\t\t\t\t\t\t  4. Class management\n\n";
    cout << "\t\t\t\t\t\t  5. Student management\n\n";
	cout << "\t\t\t\t\t\t  6. Logout\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;
    cout << "\n\t\t\t\t\t\tEnter Your Choice : "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1: Create_School_Year(); break;
        case 2: Create_Semester(); break;
        case 3: Course_Management(); break;
        case 4: Class_Management(); break;
        case 5: Student_Management(); break;
        case 6: return; 
        default: cout << "\n\t\t\t\t\t\tInvalid choice"; delay(1000);
    }

    goto reenter;
}

void Student_Add_Course() {
    system("CLS");
    cout << "Student add course - not complete";
    delay(1000);
}
void Student_Remove_Course() {
    system("CLS");
    cout << "Student remove course - not complete";
    delay(1000);
}
void Student_View_Courses() {
    system("CLS");
    cout << "Student view course - not complete";
    delay(1000);
}
void Student_View_Scoreboard() {
    system("CLS");
    cout << "Student view scoreboard - not complete";
    delay(1000);
}
void Create_School_Year() {
    system("CLS");
    cout << "Create school year - not complete";
    delay(1000);
}
void Create_Semester() {
    system("CLS");
    cout << "Create semester - not complete";
    delay(1000);
}
void Course_Management() {
    system("CLS");
    cout << "course mangement - not complete";
    delay(1000);
}
void Class_Management() {
    system("CLS");
    cout << "class management - not complete";
    delay(1000);
}
void Student_Management() {
    system("CLS");
    cout << "student management - not complete";
    delay(1000);
}
#endif // !WINDOW_H
