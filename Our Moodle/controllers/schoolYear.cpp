#include "../models/SchoolYear.h"

int YEAR;

bool isValidYear(string year) {
    while (year.size() > 1) year.erase(0, 1);
    for (int c : year) if (c < '0' || '9' < c) return 0;
    return 1;
}
void setCurrentYear(string year) {
    YEAR = stoi(year);
}
int getCurrentYear() {
    return YEAR;
}