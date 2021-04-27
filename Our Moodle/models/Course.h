#ifndef INCLUDE_COURSE_H
#define INCLUDE_COURSE_H
#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>
#include "semester.h"
#include "../utils/vector.h"
#include "user.h"

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

void addCourse(Course course);
string codeOfCourse(Course course);
void getCourses(Vector<string>& courseList, Vector<Course>& courses);
void getCourseList(Vector<string>& courseList);
void removeCouses(Vector<Course>& courses, int No);
void setCurrentCourse(Course course);
Course getCurrentCourse();
void studentAddCourse(Course course);
void studentRemoveCourse(Course course);
bool isAbleToAdd(Course course);
void getStudentCourseList(Vector<string>& courseList);
void getStudentCourseList(string student, Vector<string>& courseList);
void getCourseStudentList(Course course, Vector<string>& studentList, Vector<string>& classList);

#endif