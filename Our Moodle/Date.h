#ifndef INCLUDE_DATE_H
#define INCLUDE_DATE_H

struct Date {
	/* OBJECT */
	int day, month, year;

	/* CONSTRUCTOR */
	Date() : day(), month(), year() {}
	Date(int day, int month, int year) :
		day(day), month(month), year(year)
	{}
};

#endif