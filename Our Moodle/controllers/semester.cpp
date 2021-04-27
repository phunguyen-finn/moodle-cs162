#include "../models/semester.h"

void setCurrentSemester(int year, int term, Date start, Date end) {
	string path = "data/" + to_string(year)	+ '/' + to_string(term);
	_mkdir(path.c_str());
	path = "data/" + to_string(year) + '/' + to_string(term) + "/courses";
	_mkdir(path.c_str());
	path = "data/" + to_string(year) + '/' + to_string(term) + "/students";
	_mkdir(path.c_str());

	Vector<string> classList;
	getClasses(classList);
	int n = classList.current;
	for (int i = 0; i < n; ++i) {
		Vector<string> studentList;
		getStudentList(classList[i], studentList);
		addStudentToSemester(studentList);
	}

	path = "csvFile/" + to_string(year) + '/' + to_string(term);
	_mkdir(path.c_str());
	
	path = "data/cache/currentSemester.txt";
	ofstream fout(path); 
	fout << year << '\n';
	fout << term << '\n';
	fout << start.day << ' ' << start.month << ' ' << start.year << '\n';
	fout << end.day << ' ' << end.month << ' ' << end.year << '\n';
	fout.close();

	path = "data/" + to_string(year) + '/' + to_string(term) + "/info.txt";
	fout.open(path);
	fout << year << '\n';
	fout << term << '\n';
	fout << start.day << ' ' << start.month << ' ' << start.year << '\n';
	fout << end.day << ' ' << end.month << ' ' << end.year << '\n';
	fout.close();
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