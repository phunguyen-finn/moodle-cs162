#ifndef INCLUDE_COURSE_H
#define INCLUDE_COURSE_H

#include "Semester.h"

const int c_NSemester = 3;

struct SchoolYear {
	/* OBJECT */
	int year;

	/* LINK */
	Semester semester[c_NSemester];
};

#endif