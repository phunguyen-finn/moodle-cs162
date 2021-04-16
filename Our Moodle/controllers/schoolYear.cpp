#include "../models/SchoolYear.h"
#include "../utils/vector.h"

Vector<SchoolYear> schoolYears;

int findSchoolYearByYear(int year) {
	for (int i = 0; i < schoolYears.size(); i++)
		if (schoolYears[i].year == year) return i;
	return -1;
}

bool addSchoolYearByYear(int year) {
	if (findSchoolYearByYear(year) != -1) return false;
	schoolYears.push(SchoolYear(year));
	return true;
}