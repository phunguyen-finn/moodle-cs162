#include "../models/Course.h"

void addCourse(Course course) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;
	string courseCode = codeOfCourse(course);

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode;
	_mkdir(path.c_str());

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/info.txt";
	ofstream fout(path);
	fout << course.id << '\n';
	fout << course.name << '\n';
	fout << course.teacher << '\n';
	fout << course.nCredits << '\n';
	fout << course.maxCapacity << '\n';
	fout << course.day1 << ' ' << course.ses1 << '\n';
	fout << course.day2 << ' ' << course.ses2 << '\n';
	fout.close();

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/courseList.txt";
	fout.open(path, ofstream::out | ofstream::app);
	fout << courseCode << '\n';
	fout.close();
}
string codeOfCourse(Course course) {
	string code = course.id + "-" + course.teacher + "-" + course.day1 + course.ses1 + "-" + course.day2 + course.ses2;
	for (int i = (int)code.size() - 1; i > 0; --i)
		if (code[i] == ' ') code.erase(i, 1);
	return code;
}
void getCourses(Vector<Course>& courses) {
	string id, name, teacher;
	int nCredits, maxCapacity;
	string day1, ses1, day2, ses2;

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	Vector<string> courseList;
	getCourseList(courseList);

	int n = courseList.current;
	for (int i = 0; i < n; ++i) {
		string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseList[i] + "/info.txt";
		ifstream fin(path);
		getline(fin, id);
		getline(fin, name);
		getline(fin, teacher);
		fin >> nCredits;
		fin >> maxCapacity;
		fin >> day1 >> ses1;
		fin >> day2 >> ses2;
		fin.close();

		courses.push(Course(id, name, teacher, nCredits, maxCapacity, day1, ses1, day2, ses2));
	}
}
void getCourseList(Vector<string>& courseList) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/courseList.txt";
	ifstream fin(path);
	string dir; 
	while (fin >> dir) courseList.push(dir);
	fin.close();
}
void removeCouses(Vector<Course>& courses, int No) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;
	string courseCode = codeOfCourse(courses[No]);
	courses.erase(No); 
	int n = courses.current;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/info.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/students.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/marks.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode;
	_rmdir(path.c_str());

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/courseList.txt";
	ofstream fout(path);
	for (int i = 0; i < n; ++i)
		fout << codeOfCourse(courses[i]) << '\n';
	fout.close();
}