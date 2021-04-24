#include "../models/courseManagementSystem.h"

void LoginWindow()
{
reenter:

    string username, password;
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

    fflush(stdin);
    gotoxy(59, 25); cin >> username;
    gotoxy(59, 27); char character;
    while (character = _getch(), character != 13)
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

    if (adminLogin(username, password)) staffMenu(); else
        if (studentLogin(username, password)) studentMenu(); else {
            cout << "\n\n\t\t\t\t\t\t"; cout << "Unsuccessful login attemp";
            delay(1500);
        }
    goto reenter;
}
