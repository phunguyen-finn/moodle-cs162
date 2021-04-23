#ifndef INCLUDE_SCHOOLYEAR_H
#define INCLUDE_SCHOOLYEAR_H

#include <string>
using namespace std;

int YEAR;

bool isValidYear(string year) {
    while (year.size() > 1) year.erase(0, 1);
    for(int c: year) if (c < '0' || '9' < c) return 0;
    return 1;
}
void setCurrentYear(string year) {
    YEAR = stoi(year);
}
int getCurrentYear() {
    return YEAR;
}

#endif