#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <string>
#include <fstream>
#include <iostream>
#include <direct.h>

#include "../utils/vector.h"
#include "Date.h"
#include "user.h"
#include "mark.h"
using namespace std;

struct Student {
	string id;
	string firstName;
	string lastName;
	string gender;
	Date dob; // date of birth
	string socialId;
	string className;

	Student(string id, string firstName, string lastName, string gender, Date dob, string socialId, string className) :
		id(id), firstName(firstName), lastName(lastName), gender(gender), dob(dob), socialId(socialId), className(className)
	{};
	Student() {};
};

void studentAddCourse(int year, int term, string student, string Class, string course);
void studentRemoveCourse(int year, int term, string student, string course, Vector<string>& courseList, Vector<string>& studentList, Vector<string>& classList);

void getStudentCourseList(int year, int term, string student, Vector<string>& courseList);

void addStudentMark(int year, int term, string student, string course, Mark mark);
void addStudentMark(string student, string Class, float mark);
void getStudentScoreboard(int year, int term, string student, Vector<string>& courseList, Vector<Mark>& marks);
float getStudentGPA(string student, string Class);
#endif