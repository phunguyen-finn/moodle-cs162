#include "../models/semester.h"

void setCurrentSemester(int year, int term, Date start, Date end) {
	string path = "data/" + to_string(year) + '/' + to_string(term) + "/info.txt";
	ofstream fout(path);
	fout << year << '\n';
	fout << term << '\n';
	fout << start.day << ' ' << start.month << ' ' << start.year << '\n';
	fout << end.day << ' ' << end.month << ' ' << end.year << '\n';
	fout.close();

	path = "data/cache/currentSemester.txt";
	fout.open(path);
	fout << year << '\n';
	fout << term << '\n';
	fout << start.day << ' ' << start.month << ' ' << start.year << '\n';
	fout << end.day << ' ' << end.month << ' ' << end.year << '\n';
	fout.close();

	path = "data/" + to_string(year)	+ '/' + to_string(term);
	_mkdir(path.c_str());
	path = "data/" + to_string(year) + '/' + to_string(term) + "/courses";
	_mkdir(path.c_str());
	path = "data/" + to_string(year) + '/' + to_string(term) + "/students";
	_mkdir(path.c_str());


	path = "csvFile/" + to_string(year) + '/' + to_string(term);
	_mkdir(path.c_str());
}
Semester getCurrentSemester() {
	int year;
	int term; 
	int startday, startmonth, startyear;
	int endday, endmonth, endyear;
	
	string path = "data/cache/currentSemester.txt";
	ifstream fin(path);
	fin >> year;
	fin >> term;
	fin >> startday >> startmonth >> startyear;
	fin >> endday >> endmonth >> endyear;
	fin.close();

	return Semester(year, term, Date(startday, startmonth, startyear), Date(endday, endmonth, endyear));
}
void setCourseRegistration(Date start, Date end) {
	Semester semester = getCurrentSemester();

	string path = "data/" + to_string(semester.year) + '/' + to_string(semester.term) + "/registration.txt";
	ofstream fout(path);
	fout << start.day << ' ' << start.month << ' ' << start.year << '\n';
	fout << end.day << ' ' << end.month << ' ' << end.year << '\n';
	fout.close();
}
void addStudentToSemester(Vector<string> &students) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	int n = students.current;
	for (int i = 0; i < n; ++i) {
		string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + students[i];
		_mkdir(path.c_str());
	}
}
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
void getCourses(Vector<string>& courseList, Vector<Course>& courses) {
	string id, name, teacher;
	int nCredits, maxCapacity;
	string day1, ses1, day2, ses2;

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

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
void removeCourse(Vector<Course>& courses, int No) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string courseCode = codeOfCourse(courses[No]);
	Course deletedCourse = courses[No];
	courses.erase(No);
	int n = courses.current;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/courseList.txt";
	ofstream fout(path);
	for (int i = 0; i < n; ++i) fout << codeOfCourse(courses[i]) << '\n';
	fout.close();

	Vector<string> studentList, classList, courseList;
	getCourseStudentList(year, term, deletedCourse, studentList, classList);
	n = studentList.current;

	for (int i = 0; i < n; ++i) {
		string student = studentList[i];
		getStudentCourseList(year, term, student, courseList);
		int m = courseList.current;

		string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
		ofstream fout(path);
		for (int j = 0; j < m; ++j)
			if (courseList[j] != courseCode)
				fout << courseList[j] << '\n';
		fout.close();
	}

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/info.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/students.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/marks.txt";
	remove(path.c_str());
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode;
	_rmdir(path.c_str());
}