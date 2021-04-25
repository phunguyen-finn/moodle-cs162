#include "../models/Class.h"

void createClass(string className) {
	Semester semester = getCurrentSemester();
	int year = semester.year;
	int term = semester.term;

	string path = "data/" + to_string(year) + '/' + to_string(term) + "/classes/" + className;
	_mkdir(path.c_str());

	path = "data/" + to_string(year) + '/' + to_string(term) + "/classes/classList.txt";
	ofstream fout;
	fout.open(path, std::fstream::app);
	fout << className << '\n';
	fout.close();
}