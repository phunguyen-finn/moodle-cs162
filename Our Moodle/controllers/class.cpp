#include "../models/Class.h"

void createClass(string className) {
	string path = "data/classes/" + className;
	_mkdir(path.c_str());

	path = "data/classes/classList.txt";
	ofstream fout;
	fout.open(path, std::fstream::app);
	fout << className << '\n';
	fout.close();
}
void getClasses(Vector<string> &Classes) {
	string path = "data/classes/classList.txt";
	ifstream fin(path);
	string name;
	while (fin >> name) Classes.push(name);
	fin.close();
}
void setCurrentClass(string className) {
	string path = "data/currentClass.txt";
	ofstream fout(path);
	fout << className;
	fout.close();
}
string getCurrentClass() {
	string path = "data/currentClass.txt";
	ifstream fin(path);
	string name; fin >> name;
	fin.close(); return name;
}
void getStudentList(string className, Vector<string>& studentList) {
	string path = "data/classes/" + className + "/studentList.txt";
	ifstream fin(path);
	string id;
	while (fin >> id) studentList.push(id);
	fin.close();
}