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
	string path = "data/cache/currentClass.txt";
	ofstream fout(path);
	fout << className;
	fout.close();
}
string getCurrentClass() {
	string path = "data/cache/currentClass.txt";
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
void addStudents(string className, Vector<string>& studentList) {
	Vector<Student> students;
	importStudents(className, students);
	int n = students.current;

	string path = "data/classes/" + className + "/studentList.txt";
	ofstream fout(path);
	for (int i = 0; i < n; ++i) {
		fout << students[i].id << '\n';
		studentList.push(students[i].id);
		addAccount(User(students[i].id, students[i].socialId, "student", className));
	}
	fout.close();

	for (int i = 0; i < n; ++i) {
		path = "data/classes/" + className + "/" + students[i].id + ".txt";
		fout.open(path);
		fout << students[i].id << '\n';
		fout << students[i].firstName << '\n';
		fout << students[i].lastName << '\n';
		fout << students[i].gender << '\n';
		fout << students[i].dob.day << ' ' << students[i].dob.month << ' ' << students[i].dob.year << '\n';
		fout << students[i].socialId << '\n';
		fout << students[i].className << '\n';
		fout.close();
	}
}
void importStudents(string className, Vector<Student>& students) {
	int No;
	string id;
	string firstName;
	string lastName;
	string gender;
	Date dob;
	string socialId;

	string path = "csvFile/classes/" + className + ".csv";
	ifstream fin(path);
	string sub; getline(fin, sub);
	while (fin >> No) {
		fin.ignore();
		getline(fin, id, ',');
		getline(fin, firstName, ',');
		getline(fin, lastName, ',');
		getline(fin, gender, ',');
		fin >> dob.day; fin.ignore();
		fin >> dob.month; fin.ignore();
		fin >> dob.year; fin.ignore();
		getline(fin, socialId, '\n');

		students.push(Student(id, firstName, lastName, gender, dob, socialId, className));
	}
	fin.close();
}
void getStudents(string className, Vector<Student>& students) {
	string id;
	string firstName;
	string lastName;
	string gender;
	Date dob;
	string socialId;

	Vector<string> studentList;
	getStudentList(className, studentList);

	int n = studentList.current;
	for (int i = 0; i < n; ++i) {
		string path = "data/classes/" + className + "/" + studentList[i] + ".txt";
		ifstream fin(path);
		getline(fin, id);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, gender);
		fin >> dob.day >> dob.month >> dob.year; fin.ignore();
		getline(fin, socialId);
		fin.close();

		students.push(Student(id, firstName, lastName, gender, dob, socialId, className));
	}
}
void getStudents(Vector<string>& studentList, Vector<string>& classList, Vector<Student>& students) {
	string id;
	string firstName;
	string lastName;
	string gender;
	Date dob;
	string socialId;

	int n = studentList.current;
	for (int i = 0; i < n; ++i) {
		string path = "data/classes/" + classList[i] + "/" + studentList[i] + ".txt";
		ifstream fin(path);
		getline(fin, id);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, gender);
		fin >> dob.day >> dob.month >> dob.year; fin.ignore();
		getline(fin, socialId);
		fin.close();

		students.push(Student(id, firstName, lastName, gender, dob, socialId, classList[i]));
	}
}