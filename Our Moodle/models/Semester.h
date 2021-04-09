#ifndef HEADER_SEMESTER_INCLUDED
#define HEADER_SEMESTER_INCLUDED

#include <string>
#include "Date.h"

using namespace std;

struct Semester {
	/* OBJECT */
	string name; // Fall, Spring, Summer,... etc
	Date startDate, endDate;

	/* LINK */
	int nClass; // number of students
	string* classesId; // list of students
	int nCourse; // number of course
	string* coursesId; // list of courses
	int year; // belong to which school year
};

#endif
