#ifndef INCLUDE_DATE_H
#define INCLUDE_DATE_H

#include <ctime>
#include <iostream>
using namespace std;

struct Date {
	/* OBJECT */
	int day, month, year;

	/* CONSTRUCTOR */
	Date(int day = -1, int month = -1, int year = -1) :
		day(day), month(month), year(year)
	{};

	/* OPERATOR */
	bool operator < (Date b) {
		if (year != b.year) return year < b.year;
		if (month != b.month) return month < b.month;
		return day < b.day;
	}
	bool operator == (Date b) {
		return *(this) == b;
	}
	bool operator <= (Date b) {
		return *(this) < b || *(this) == b;
	}
};

Date getCurrentDate();

#endif