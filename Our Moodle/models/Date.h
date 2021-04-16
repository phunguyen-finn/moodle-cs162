#ifndef INCLUDE_DATE_H
#define INCLUDE_DATE_H

struct Date {
	/* OBJECT */
	int day, month, year;

	/* CONSTRUCTOR */
	Date(int day = -1, int month = -1, int year = -1) :
		day(day), month(month), year(year)
	{}
};

#endif