#ifndef HEADER_SEMESTER_INCLUDED
#define HEADER_SEMESTER_INCLUDED

#include "Date.h"
#include "schoolYear.h"
#include "../utils/vector.h"
#include "course.h"
#include "student.h"

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

void setCourseRegistration(Date start, Date end);
void setCurrentSemester(int year, int term, Date start, Date end);
Semester getCurrentSemester();

void addCourse(Course course);
void removeCourse(Vector<Course>& courses, int No);
void getCourseList(Vector<string>& courseList);
void getCourses(Vector<string>& courseList, Vector<Course>& courses);

void addStudentToSemester(Vector<string> &students);

#endif
