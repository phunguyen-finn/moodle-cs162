#include "../models/date.h"

Date getCurrentDate() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    int year = 1900 + newtime.tm_year;
    int month = 1 + newtime.tm_mon;
    int day = newtime.tm_mday;

    return Date(day, month, year);
}