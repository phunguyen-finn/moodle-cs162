#ifndef HEADER_CLASS_INCLUDED
#define HEADER_CLASS_INCLUDED

#include <string>
#include <fstream>
#include <iostream>
#include <direct.h>

#include "../utils/vector.h"
#include "student.h"
using namespace std;

void createClass(string className);
void getClasses(Vector<string> &Classes);
void setCurrentClass(string className);
string getCurrentClass();

void addStudents(string className, Vector<string>& studentList);
void getStudentList(string className, Vector<string>& studentList);
void getStudents(string className, Vector<Student>& students);
void getStudents(Vector<string>& studentList, Vector<string>& classList, Vector<Student>& students);
void importStudents(string className, Vector<Student>& students);
#endif
