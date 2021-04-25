#include "../models/commandReader.h"

bool readInt(int& number) {
	fflush(stdin);
	string input;
	cin >> input;
	for (char c : input) if (c < '0' || '9' < c) return 0;
	number = stoi(input);
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