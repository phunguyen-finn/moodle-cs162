#include "../models/Course.h"


string codeOfCourse(Course course) {
	string code = course.id + "-" + course.teacher + "-" + course.day1 + course.ses1 + "-" + course.day2 + course.ses2;
	for (int i = (int)code.size() - 1; i > 0; --i)
		if (code[i] == ' ') code.erase(i, 1);
	return code;
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
void getCourseStudentList(int year, int term, Course course, Vector<string>& studentList, Vector<string>& classList) {
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
void exportCourse(int year, int term, string course, Vector<string>& id, Vector<string>& fullname) {
	int n = fullname.current;

	string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + course + ".csv";
	ofstream fout(path);
	fout << "No,Student ID,Full name,Total mark,Final mark,Midterm mark,Other mark\n";
	for (int i = 0; i < n; ++i) {
		fout << i + 1 << ',';
		fout << id[i] << ',';
		fout << fullname[i] << ',';
		fout << ','; // total mark,
		fout << ','; // final mark,
		fout << ','; // midterm mark,
		fout << '\n'; // other mark
	}
	fout.close();
}
void importCourse(int year, int term, string course, Vector<string>& ids, Vector<string>& fullnames, Vector<Mark>& marks) {
	int No;
	float totalMark, finalMark, midtermMark, otherMark;
	string id, fullName;

	string path = "csvFile/" + to_string(year) + "/" + to_string(term) + "/" + course + ".csv";
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

		ids.push(id);
		fullnames.push(fullName);
		marks.push(Mark(totalMark, finalMark, midtermMark, otherMark));
	}
	fin.close();
}
void updateCourseMark(int year, int term, string course, Vector<string>& students, Vector<string>& names, Vector<Mark>& marks) {
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + course + "/marks.txt";
	ofstream fout(path);
	fout.precision(2);
	int n = students.current;
	for (int i = 0; i < n; ++i) {
		fout << students[i] << ' ' << fixed << marks[i].totalMark << ' ' << marks[i].finalMark << ' ' << marks[i].midtermMark << ' ' << marks[i].otherMark << ' ' << names[i] << '\n';
	}
	fout.close();
}
void getCourseScoreboard(int year, int term, Vector<string>& students, Vector<string>& names, Vector<Mark>& marks) {
	Course course = getCurrentCourse();
	string courseCode = codeOfCourse(course);

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
bool isAbleToAdd(Course course, Vector<Course>& courses) {
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