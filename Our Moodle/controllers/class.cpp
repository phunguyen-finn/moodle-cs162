#include "../models/Class.h"

Vector<Class> classes;

int findClassByName(string name) {
	for (int i = 0; i < classes.size(); i++)
		if (classes[i].name == name) return i;
	return -1;
}

bool addClass(Class newClass) {
	if (findClassByName(newClass.name) != -1) return false;
	classes.push(newClass);
	return true;
}