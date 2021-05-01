#include "../models/User.h"

User login(string username, string password) {
    Vector<User> accounts;
    getAccounts(accounts);

    int n = accounts.current;
    for (int i = 0; i < n; ++i)
        if (username == accounts[i].username && password == accounts[i].password)
            return accounts[i];
    return User("NONE", "NONE", "NONE", "NONE");
}
void getAccounts(Vector<User>& accounts) {
    string username, password, role, Class;

    string path = "data/accounts.txt";
    ifstream fin(path);
    while (fin >> username >> password >> role >> Class) 
        accounts.push(User(username, password, role, Class));
    fin.close();
}
void setAccounts(Vector<User>& accounts) {
    int n = accounts.current;

    string path = "data/accounts.txt";
    ofstream fout(path);
    for (int i = 0; i < n; ++i) 
        fout << accounts[i].username << ' ' << accounts[i].password << ' ' << accounts[i].role <<' ' << accounts[i].Class << '\n';
    fout.close();
}
void addAccount(User account) {
    string path = "data/accounts.txt";
    ofstream fout; 
    fout.open(path, ofstream::out | ofstream::app);
    fout << account.username << ' ' << account.password << ' ' << account.role << ' ' << account.Class << '\n';
    fout.close();
}
void setCurrentAccount(User account) {
    string path = "data/cache/currentAccount.txt";
    ofstream fout(path);
    fout << account.username << ' ' << account.password << ' ' << account.role << ' ' << account.Class;
    fout.close();
}
void getCurrentAccount(User& account) {
    string path = "data/cache/currentAccount.txt";
    ifstream fin(path);
    fin >> account.username >> account.password >> account.role >> account.Class;
    fin.close();
}
void changePassword(User account, string newPassword) {
    Vector<User> accounts;
    getAccounts(accounts);

    int n = accounts.current;
    for (int i = 0; i < n; ++i) if (accounts[i].username == account.username) {
        accounts[i].password = newPassword;
        break;
    }

    setAccounts(accounts);
}