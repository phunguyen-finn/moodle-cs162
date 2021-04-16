#include "../utils/vector.h"
#include "../models/Course.h"

Vector<Course> courses;

int findCourseByIdAndSemesterId(string id, int semesterId) {
	for (int i = 0; i < courses.size(); i++)
		if (courses[i].id == id && courses[i].semesterId == semesterId)
			return i;
	return -1;
}

bool addCourse(Course newCour) {
	if (findCourseByIdAndSemesterId(newCour.id, newCour.semesterId) == -1)
		return false;
	courses.push(newCour);
	return true;
}