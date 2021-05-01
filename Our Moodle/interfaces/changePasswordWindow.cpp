#include "../models/courseManagementSystem.h"

void changePasswordWindow()
{
reenter:

    system("CLS"); Heading();
    cout << "\n\n\t\t\t\t\t       ";
    for (int rep = 1; rep <= 5; rep++) cout << char(219); cout << " CHANGE PASSWORD "; for (int rep = 1; rep <= 5; rep++) cout << char(219);
    cout << "\n\n";
    cout << "\t\t\t\t\t      Current password     : \n\n";
    cout << "\t\t\t\t\t      New password         : \n\n";
    cout << "\t\t\t\t\t      Confirm new password : \n\n";
    cout << "\t\t\t\t\t      Action(commit/back)  : \n\n\n\n";
    for (int rep = 1; rep <= 120; rep++) cout << char(220); cout << endl;

    string currentPassword, newPassword, confirmPassword;
    readPassword(currentPassword, 69, 12);
    readPassword(newPassword, 69, 14);
    readPassword(confirmPassword, 69, 16);
    do {
        string confirm; gotoxy(69, 18); read(confirm);
        if (confirm == "back") return; else
            if (confirm == "commit") {
                User account; getCurrentAccount(account);
                if (account.password != currentPassword) goto oldPassNotMatch;
                if (newPassword != confirmPassword) goto newPassNotMatch;
                changePassword(account, newPassword);

                cout << "\n\t\t\t\t\t   Password has been changed successfully";
                delay(1500); return;
            }
        gotoxy(69, 18); for (char c : confirm) cout << ' ';
    } while (true);

    goto reenter;

oldPassNotMatch:
    gotoxy(46, 20); cout << "Current password is incorrect";
    delay(1500);
    goto reenter;

newPassNotMatch:
    gotoxy(46, 20); cout << "New password is incorrect";
    delay(1500);
    goto reenter;
}