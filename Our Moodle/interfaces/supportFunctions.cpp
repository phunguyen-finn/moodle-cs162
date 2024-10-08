#include "../models/courseManagementSystem.h"
#include <time.h>

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
    SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
    //set x and y to whatever ye' want
    int x = 120 - 1; // 120
    int y = 30 - 1; // 30

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DisplayArea.Right = x;
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
void Heading()
{
    Semester semester = getCurrentSemester();
    int year = semester.year;
    int term = semester.term;
    User account;
    getCurrentAccount(account);

    cout << "\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
    cout << "\n\t\t\t\t\t\tCOURSE MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t         Year: " << year << " - " << year + 1;
    cout << "\t   Semester " << term;
    if (term == 1) cout << "(Fall)"; else
        if (term == 2) cout << "(Summer)"; else
            if (term == 3) cout << "(Autumn)";
            else cout << "(NULL)";
    if (account.role == "staff") cout << "\n\t\t\t\t\t\t   Logged in as: ADMIN\n\n";
    else cout << "\n\t\t\t\t\t\t   Logged in as: " << account.username << "\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(219); cout << endl;
}