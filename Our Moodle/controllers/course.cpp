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
void removeCouses(Vector<Course>& courses, int No) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string courseCode = codeOfCourse(courses[No]);
	Course deletedCourse = courses[No];
	courses.erase(No); 
	int n = courses.current;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/courseList.txt";
	ofstream fout(path);
	for (int i = 0; i < n; ++i)
		fout << codeOfCourse(courses[i]) << '\n';
	fout.close();

	Vector<string> studentList, classList, courseList;
	getCourseStudentList(deletedCourse, studentList, classList);
	n = studentList.current;

	for (int i = 0; i < n; ++i) {
		string student = studentList[i];
		getStudentCourseList(student, courseList);
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
void setCurrentCourse(Course course) {
	string path = "data/cache/currentCourse.txt";
	ofstream fout(path);
	fout << course.id << '\n';
	fout << course.name << '\n';
	fout << course.teacher << '\n';
	fout << course.nCredits << '\n';
	fout << course.maxCapacity << '\n';
	fout << course.day1 << ' ' << course.ses1 << '\n';
	fout << course.day2 << ' ' << course.ses2 << '\n';
	fout.close();
}
Course getCurrentCourse() {
	string id, name, teacher;
	int nCredits, maxCapacity;
	string day1, ses1, day2, ses2;

	string path = "data/cache/currentCourse.txt";
	ifstream fin(path);
	getline(fin, id);
	getline(fin, name);
	getline(fin, teacher);
	fin >> nCredits;
	fin >> maxCapacity;
	fin >> day1 >> ses1;
	fin >> day2 >> ses2;
	fin.close();

	return Course(id, name, teacher, nCredits, maxCapacity, day1, ses1, day2, ses2);
}
void studentAddCourse(Course course) {
	User account;
	getCurrentAccount(account);
	string student = account.username;
	string Class = account.Class;
	string courseCode = codeOfCourse(course);

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	ofstream fout;
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	fout.open(path, ofstream::out | ofstream::app);
	fout << courseCode << '\n';
	fout.close();

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/students.txt";
	fout.open(path, ofstream::out | ofstream::app);
	fout << student << ' ' << Class << '\n';
	fout.close();
}
void studentRemoveCourse(Course course) {
	User account;
	getCurrentAccount(account);
	string student = account.username;
	string courseCode = codeOfCourse(course);

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	Vector<string> courseList; 
	getStudentCourseList(courseList);
	int n = courseList.current;
	
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	ofstream fout(path);
	for (int i = 0; i < n; ++i) 
		if (courseList[i] != courseCode) 
			fout << courseList[i] << '\n';
	fout.close();
	
	Vector<string> studentList; 
	Vector<string> classList;
	getCourseStudentList(course, studentList, classList);
	n = studentList.current;
	
	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/students.txt";
	fout.open(path);
	for (int i = 0; i < n; ++i) 
		if (studentList[i] != student) 
			fout << studentList[i] << ' ' << classList[i] << '\n';
	fout.close();
}
bool isAbleToAdd(Course course) {
	Vector<string> courseList;
	getStudentCourseList(courseList);
	Vector<Course> courses;
	getCourses(courseList, courses);

	int n = courses.current;
	if (n == 5) return 0;
	for (int i = 0; i < n; ++i)
		if ((courses[i].day1 == course.day1 && courses[i].ses1 == course.ses1) ||
			(courses[i].day1 == course.day2 && courses[i].ses1 == course.ses2) ||
			(courses[i].day2 == course.day1 && courses[i].ses2 == course.ses1) ||
			(courses[i].day2 == course.day2 && courses[i].ses2 == course.ses2))
			return 0;
	return 1;
}
void getStudentCourseList(Vector<string>& courseList) {
	User account;
	getCurrentAccount(account);
	string student = account.username;

	getStudentCourseList(student, courseList);
}
void getCourseStudentList(Course course, Vector<string>& studentList, Vector<string>& classList) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string courseCode = codeOfCourse(course);
	string student, Class;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/students.txt";
	ifstream fin(path);
	while (fin >> student >> Class) {
		studentList.push(student);
		classList.push(Class);
	}
	fin.close();
}
void getStudentCourseList(string student, Vector<string>& courseList) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	ifstream fin(path);
	string dir;
	while (fin >> dir) courseList.push(dir);
	fin.close();
}
void exportCourse(Semester semester, Course course) {
	int year = semester.year;
	int term = semester.term;
	string courseCode = codeOfCourse(course);

	Vector<string> studentList, classList;
	getCourseStudentList(course, studentList, classList);
	Vector<Student> students;
	getStudents(studentList, classList, students);
	int n = students.current;

	string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + courseCode + ".csv";
	ofstream fout(path);
	fout << "No,Student ID,Full name,Total mark,Final mark,Midterm mark,Other mark\n";
	for (int i = 0; i < n; ++i) {
		fout << i + 1 << ',';
		fout << students[i].id << ',';
		fout << students[i].lastName << ' ' << students[i].firstName << ',';
		fout << ','; // total mark,
		fout << ','; // final mark,
		fout << ','; // midterm mark,
		fout << '\n'; // other mark
	}
	fout.close();
}
void importCourse(Semester semester, Course course) {
	int year = semester.year;
	int term = semester.term;
	string courseCode = codeOfCourse(course);

	Vector<string> students, names;
	Vector<Mark> marks;
	int No;
	float totalMark, finalMark, midtermMark, otherMark;
	string id, fullName;

	string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + courseCode + ".csv";
	ifstream fin(path);
	string line; getline(fin, line);
	while (fin >> No) {
		fin.ignore();
		getline(fin, id, ',');
		getline(fin, fullName, ',');
		fin >> totalMark; fin.ignore();
		fin >> finalMark; fin.ignore();
		fin >> midtermMark; fin.ignore();
		fin >> otherMark;

		students.push(id);
		names.push(fullName);
		marks.push(Mark(totalMark, finalMark, midtermMark, otherMark));
	}
	fin.close();

	int n = students.current;
	for (int i = 0; i < n; ++i) 
		addStudentMark(students[i], courseCode, marks[i]);
	updateCourseMark(courseCode, students, names, marks);
}
void addStudentMark(string student, string course, Mark mark) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/marks.txt";
	ofstream fout;
	fout.open(path, ofstream::out | ofstream::app);
	fout.precision(2);
	fout << course << ' ' << fixed << mark.totalMark << ' ' << mark.finalMark << ' ' << mark.midtermMark << ' ' << mark.otherMark << '\n';
	fout.close();
}
void updateCourseMark(string course, Vector<string>& students, Vector<string>& names, Vector<Mark>& marks) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + course + "/marks.txt";
	ofstream fout(path);
	fout.precision(2);
	int n = students.current;
	for (int i = 0; i < n; ++i) {
		fout << students[i] << ' ' << fixed << marks[i].totalMark << ' ' << marks[i].finalMark << ' ' << marks[i].midtermMark << ' ' << marks[i].otherMark << ' ' << names[i] << '\n';
	}
	fout.close();
}
void getCourseScoreboard(Vector<string>& students, Vector<string>& names, Vector<Mark>& marks) {
	Course course = getCurrentCourse();
	string courseCode = codeOfCourse(course);

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string student, name; Mark mark;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + courseCode + "/marks.txt";
	ifstream fin(path);
	while (fin >> student >> mark.totalMark >> mark.finalMark >> mark.midtermMark >> mark.otherMark) {
		fin.ignore();
		getline(fin, name);
		students.push(student);
		names.push(name);
		marks.push(mark);
	}
	fin.close();
}
void getStudentScoreboard(Vector<string>& courses, Vector<string>& names, Vector<Mark>& marks) {
	User account;
	getCurrentAccount(account);
	string student = account.username;

	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	Vector<string> courseList;
	string courseCode;
	Mark mark;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/marks.txt";
	ifstream fin(path);
	while (fin >> courseCode >> mark.totalMark >> mark.finalMark >> mark.midtermMark >> mark.otherMark) {
		courseList.push(courseCode);
		marks.push(mark);
	}
	fin.close();

	Vector<Course> Courses;
	getCourses(courseList, Courses);
	int n = Courses.current;
	for (int i = 0; i < n; ++i) {
		courses.push(Courses[i].id);
		names.push(Courses[i].name);
	}
}