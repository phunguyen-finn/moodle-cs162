#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "date.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool readInt(int &number);
bool readDate(Date &date);
bool read(string& str);
bool readLine(string& str);
bool readFloat(float& number);
void readPassword(string& password, int x, int y);
void gotoxyCommandReader(int x, int y);
#endif
