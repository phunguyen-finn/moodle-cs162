#include "../models/commandReader.h"

bool readInt(int& number) {
	fflush(stdin);
	string input;
	cin >> input;
	for (char c : input) if (c < '0' || '9' < c) return 0;
	number = stoi(input);
	return 1;
}
bool readFloat(float& number) {
	fflush(stdin);
	string input; cin >> input;
	bool dot = 1;
	for (char c : input)
		if (c == '.' && dot) dot = 0; else  
			if (c < '0' || '9' < c) return 0;
	number = stof(input);
	return 1;
}

bool readDate(Date& date) {
	// dd/mm/yyyy
	fflush(stdin);
	string input;
	cin >> input;
	if (input.size() != 10) return 0;
	for(int i=0; i<10; ++i) 
		if (i == 2 || i == 5) {
			if (input[i] != '/') return 0;
		}
		else {
			if (input[i] < '0' || '9' < input[i]) return 0;
		}
	date = Date(stoi(input.substr(0, 2)), stoi(input.substr(3, 2)), stoi(input.substr(6, 4)));
	return 1;
}
bool read(string& str) {
	fflush(stdin);
	string input;
	cin >> input;
	str = input;
	return 1;
}
bool readLine(string& str) {
	fflush(stdin);
	string input;
	getline(cin, input);
	str = input;
	return 1;
}
void readPassword(string& password, int x, int y) {
	gotoxyCommandReader(x, y); char character;
	while (character = _getch(), character != 13)
		if (character == '\b') {
			if (password.size() == 0) continue;
			password.pop_back();
			gotoxyCommandReader(x + (int)password.size(), y); cout << ' ';
			gotoxyCommandReader(x + (int)password.size(), y);
		}
		else {
			password += character;
			cout << "*";
		}
}
void gotoxyCommandReader(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}