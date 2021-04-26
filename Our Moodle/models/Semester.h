#ifndef HEADER_SEMESTER_INCLUDED
#define HEADER_SEMESTER_INCLUDED

#include "Date.h"
#include "schoolYear.h"
#include "class.h"
#include "../utils/vector.h"
#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>
using namespace std;

struct Semester {
	int year, term;
	Date startDate, endDate;

	Semester(int year, int term, Date start, Date end) : year(year), term(term), startDate(start), endDate(end) {};
};

void setCurrentSemester(int year, int term, Date start, Date end);
void setCourseRegistration(Date start, Date end);
Semester getCurrentSemester();
void addStudentToSemester(Vector<string> &students);

#endif
