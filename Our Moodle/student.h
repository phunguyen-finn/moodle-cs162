#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <string>
#include "Date.h"

using namespace std;

struct Student {
	/* OBJECT */
	int id;
	string firstName;
	string LastName;
	bool gender; // 0 = female, 1 = male
	Date dob; // date of birth
	string socialId;

	/* LINK */
	string classId;
	string* coursesId;
};
#endif