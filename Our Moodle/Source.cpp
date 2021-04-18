#include <iostream>
// #include "./models/SchoolYear.h"
#include "./interfaces/Window.h"

using namespace std;

#define ADMIN 1
#define STUDENT 2

// extern SchoolYear* schoolYear;

int main() {
	
	set_console_size();
	Loading();
	LoginWindow(); 
	
	system("pause");
	return 0;
}