#ifndef HEADER_CLASS_INCLUDED
#define HEADER_CLASS_INCLUDED

#include <string>
#include "../utils/vector.h"
#include <fstream>
#include <iostream>
#include <direct.h>
using namespace std;

void createClass(string className);
void getClasses(Vector<string> &Classes);
void setCurrentClass(string className);
string getCurrentClass();
void getStudentList(string className, Vector<string>& studentList);

#endif
