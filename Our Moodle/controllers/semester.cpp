#include "../models/semester.h"

void setCurrentSemester(int year, int term, Date start, Date end) {
	string path = "data/" + to_string(year)	+ '/' + to_string(term);
	_mkdir(path.c_str());

	path = "data/" + to_string(year) + '/' + to_string(term) + "/classes";
	_mkdir(path.c_str());
	path = "data/" + to_string(year) + '/' + to_string(term) + "/courses";
	_mkdir(path.c_str());
	
	path = "data/" + to_string(year) + "/currentSemester.txt";
	ofstream fout(path); 
	fout << term;
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
	int year = getCurrentYear();
	int term; 
	int startday, startmonth, startyear;
	int endday, endmonth, endyear;
	
	string path = "data/" + to_string(year) + "/currentSemester.txt";
	ifstream fin(path);
	fin >> term;
	fin.close();

	path = "data/" + to_string(year) + '/' + to_string(term) + "/info.txt";
	fin.open(path);
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
