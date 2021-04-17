#ifndef INCLUDE_COURSE_H
#define INCLUDE_COURSE_H
#include <string>
#include "../utils/vector.h"

using namespace std;

const int c_NWeekDay = 6,
c_MaxCapInit = 50;

struct Course {
	/* OBJECT */
	string id;
	string name;
	string teacher;
	int nCredit; // number of credits
	int *session; // sessions the course is taught during weekdays
	int maxCapacity; // maximum number of students

	/* LINK */
	int semesterId;
	Vector<int> studentsId; // list of students ID

	/* CONSTRUCTOR */
	Course(): maxCapacity(c_MaxCapInit), nCredit(), session(), studentsId(), semesterId() {
		session = new int[c_NWeekDay];
	}
};
#endif