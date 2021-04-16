#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <string>
#include "../utils/vector.h"
#include "Date.h"

using namespace std;

struct Student {
	/* OBJECT */
	int id;
	string firstName;
	string lastName;
	bool gender; // 0 = female, 1 = male
	Date dob; // date of birth
	string socialId;

	/* LINK */
	string classId;
	Vector<string> coursesId;
};
#endif