#ifndef HEADER_CLASS_INCLUDED
#define HEADER_CLASS_INCLUDED

#include <string>
#include "..\utils\vector.h"

using namespace std;

struct Class {
	/* OBJECT */
	string name;

	/* LINK */
	int yearOfClass; // the school year that this class is first introduced

	Class(): name(), yearOfClass() {}
};

#endif
