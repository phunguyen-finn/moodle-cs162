#ifndef INCLUDE_COURSE_H
#define INCLUDE_COURSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>

#include "mark.h"
#include "../utils/vector.h"
using namespace std;

struct Course {
	/* OBJECT */
	string id;
	string name;
	string teacher;
	int nCredits; 
	int maxCapacity; 
	string day1, ses1;
	string day2, ses2;

	/* CONSTRUCTOR */
	Course(string id, string name, string teacher, int nCredits, int maxCapacity, string day1, string ses1, string day2, string ses2) :
		id(id), name(name), teacher(teacher), nCredits(nCredits), maxCapacity(maxCapacity), day1(day1), ses1(ses1), day2(day2), ses2(ses2)
	{};
	Course() {};
};

string codeOfCourse(Course course);
void setCurrentCourse(Course course);
Course getCurrentCourse();

void getCourseStudentList(int year, int term, Course course, Vector<string>& studentList, Vector<string>& classList);
void exportCourse(int year, int term, string course, Vector<string>& id, Vector<string>& fullname);
void importCourse(int year, int term, string course, Vector<string>& ids, Vector<string>& fullnames, Vector<Mark>& marks);

void updateCourseMark(int year, int term, string course, Vector<string>& students, Vector<string>& names, Vector<Mark>& marks);
void updateCourseMark(int year, int term, string course, string student, Mark mark);
void getCourseScoreboard(int year, int term, Vector<string>& students, Vector<string>& names, Vector<Mark>& marks, string course = codeOfCourse(getCurrentCourse()));

bool isAbleToAdd(Course course, Vector<Course>& courses);
#endif