#include "../models/Student.h"

void studentAddCourse(int year, int term, string student, string Class, string course) {ofstream fout;
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	fout.open(path, ofstream::out | ofstream::app);
	fout << course << '\n';
	fout.close();

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + course + "/students.txt";
	fout.open(path, ofstream::out | ofstream::app);
	fout << student << ' ' << Class << '\n';
	fout.close();
}
void studentRemoveCourse(int year, int term, string student, string course, Vector<string>& courseList, Vector<string>& studentList, Vector<string>& classList) {
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	ofstream fout(path);
	int n = courseList.current;
	for (int i = 0; i < n; ++i)
		if (courseList[i] != course)
			fout << courseList[i] << '\n';
	fout.close();

	path = "data/" + to_string(year) + "/" + to_string(term) + "/courses/" + course + "/students.txt";
	fout.open(path);
	n = studentList.current;
	for (int i = 0; i < n; ++i)
		if (studentList[i] != student)
			fout << studentList[i] << ' ' << classList[i] << '\n';
	fout.close();
}
void getStudentCourseList(int year, int term, string student, Vector<string>& courseList) {
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/courses.txt";
	ifstream fin(path);
	string dir;
	while (fin >> dir) courseList.push(dir);
	fin.close();
}
void addStudentMark(int year, int term, string student, string course, Mark mark) {
	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/marks.txt";

	Vector<string> courses; Vector<Mark> marks;
	string courseTmp; Mark markTmp;

	ifstream fin(path);
	courses.push(course);
	marks.push(mark);
	while (fin >> courseTmp >> markTmp.totalMark >> markTmp.finalMark >> markTmp.midtermMark >> markTmp.otherMark) 
		if (courseTmp != course) {
			courses.push(courseTmp); 
			marks.push(markTmp);
		}
	fin.close();
	
	ofstream fout(path);
	fout.precision(2);
	int n = marks.current;
	for (int i = 0; i < n; ++i) {
		fout << courses[i] << ' ';
		fout << fixed << marks[i].totalMark << ' ';
		fout << fixed << marks[i].finalMark << ' ';
		fout << fixed << marks[i].midtermMark << ' ';
		fout << fixed << marks[i].otherMark << '\n';
	}
	fout.close();
}
void getStudentScoreboard(int year, int term, string student, Vector<string>& courseList, Vector<Mark>& marks) {
	string courseCode; Mark mark;

	string path = "data/" + to_string(year) + "/" + to_string(term) + "/students/" + student + "/marks.txt";
	ifstream fin(path);
	while (fin >> courseCode >> mark.totalMark >> mark.finalMark >> mark.midtermMark >> mark.otherMark) {
		courseList.push(courseCode);
		marks.push(mark);
	}
	fin.close();
}
float getStudentGPA(string student, string Class) {
	string path = "data/classes/" + Class + "/" + student + "_marks.txt";
	ifstream fin(path);
	float mark, sum = 0;
	int cnt = 0;
	while (fin >> mark) {
		sum += mark;
		cnt += 1;
	}
	fin.close();
	float GPA = cnt > 0 ? sum / cnt : 0;
	return GPA / 10 * 4;
}
void addStudentMark(string student, string Class, float mark) {
	string path = "data/classes/" + Class + "/" + student + "_marks.txt";
	ofstream fout;
	fout.open(path, std::ofstream::out | std::ofstream::app);
	fout << mark << '\n';
	fout.close();
}
void updateStudentMark(string student, string Class, float mark, float markNew) {
	Vector<float> marks;

	string path = "data/classes/" + Class + "/" + student + "_marks.txt";
	ifstream fin(path);
	float markTmp;
	while (fin >> markTmp) marks.push(markTmp);
	fin.close();

	int n = marks.current;
	for (int i = 0; i < n; ++i) if (marks[i] == mark) {
		marks[i] = markNew; 
		break;
	}

	ofstream fout(path);
	for (int i = 0; i < n; ++i) fout << marks[i] << '\n';
	fout.close();
}