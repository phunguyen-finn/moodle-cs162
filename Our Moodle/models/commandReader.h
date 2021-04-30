#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "date.h"
#include <string>
#include <iostream>
using namespace std;

bool readInt(int &number);
bool readDate(Date &date);
bool read(string& str);
bool readLine(string& str);
bool readFloat(float& number);

#endif
