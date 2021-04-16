#include "../models/Student.h"
#include "../utils/vector.h"

Vector<Student> students;

int findStudentById(int id) {
	for (int i = 0; i < students.size(); i++)
		if (students[i].id == id) return i;
	return -1;
}

bool addStudent(Student newStud) {
	if (findStudentById(newStud.id) != -1) return false;
	students.push(newStud);
	return true;
}