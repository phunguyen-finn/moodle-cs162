#ifndef INCLUDE_SCHOOLYEAR_H
#define INCLUDE_SCHOOLYEAR_H

#include "Semester.h"

struct SchoolYear {
	/* OBJECT */
	int year;

	/* CONSTRUCTOR */
	SchoolYear(): year() {}
	SchoolYear(int year) : year(year) {}
};

int findSchoolYearByYear(int year);
bool addSchoolYearByYear(int year);

#endif