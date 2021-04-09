#ifndef HEADER_CLASS_INCLUDED
#define HEADER_CLASS_INCLUDED

#include <string>

using namespace std;

struct Class {
	/* OBJECT */
	string id;

	/* LINK */
	int yearOfClass; // the school year that this class is first introduced
	int nStudent; // number of students
	string* studentsId; // list of students
};

#endif
