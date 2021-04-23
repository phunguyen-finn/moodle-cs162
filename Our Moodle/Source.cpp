#include <iostream>
#include "./interfaces/Window.h"

using namespace std;

// extern SchoolYear* schoolYear;

int main() {
	
	set_console_size();
	Loading();
	LoginWindow(); 
	
	return 0;
}