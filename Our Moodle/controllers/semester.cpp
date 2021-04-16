#include "../models/Semester.h"
#include "../utils/vector.h"

Vector<Semester> semesters;

bool addSemester(Semester newSem) {
	newSem.auto_id = semesters.size();
	semesters.push(newSem);
}