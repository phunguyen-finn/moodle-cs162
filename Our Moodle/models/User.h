#ifndef INCLUDE_USER_H
#define INCLUDE_USER_H

#include <string>
#include "../utils/vector.h"
#include <iostream>
#include <fstream>
using namespace std;

struct User {
	/* OBJECT */
	string username;
	string password;
	string role;
	string Class;

	User(string username, string password, string role, string Class) :
		username(username), password(password), role(role), Class(Class) {};
	User() {};
};

User login(string username, string password);
void getAccounts(Vector<User>& accounts);
void setAccounts(Vector<User>& accounts);
void addAccount(User account);
void setCurrentAccount(User account);
void getCurrentAccount(User& account);
#endif