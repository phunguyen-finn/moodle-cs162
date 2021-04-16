#ifndef INCLUDE_USER_H
#define INCLUDE_USER_H

#include <string>

using namespace std;

struct User {
	/* OBJECT */
	string username;
	string password;
	bool isStudent;
};

#endif