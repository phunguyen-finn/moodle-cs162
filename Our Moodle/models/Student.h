#ifndef INCLUDE_STUDENT_H
#define INCLUDE_STUDENT_H

#include <string>
#include "../utils/vector.h"
#include "Date.h"
#include "semester.h"
#include <fstream>
#include <iostream>
#include <direct.h>
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

void addStudents(string className);
void importStudents(string className, Vector<Student> &students);
#endif