#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include <conio.h>
//Color:
//Black | 0
//Blue | 1
//Green | 2
//Cyan | 3
//Red | 4
//Magenta | 5
//Brown | 6
//Light Gray | 7
//Dark Gray | 8
//Light Blue | 9agenta()
//Light Green | 10
//Light Cyan | 11
//Light Red | 12
//Light Magenta | 13
//Yellow | 14
//White | 15
void Black() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
void Blue() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}
void Green() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}
void Cyan() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}
void Red() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
}
void Magenta() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
}
void Brown() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}
void LightGray() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void DarkGray() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}
void LightBlue() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}
void LightGreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}
void LightCyan() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}
void LightRed() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}
void LightMagenta() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
}
void Yellow() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}
void White() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//=======
HANDLE hConsoleOutput;
HANDLE hConsoleInput;

// Resize the Console Window
void resizeConsole(SHORT width, SHORT height)
{
	/*HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);*/

	COORD crd = { width, height };
	SMALL_RECT rec = { 0, 0, width - 1, height - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(hConsoleOutput, TRUE, &rec);
	SetConsoleScreenBufferSize(hConsoleOutput, crd);
}

// Delete Window data.
void clrscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	COORD Home = { 0, 0 };
	DWORD dummy;

	hConsoleOutput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	FillConsoleOutputCharacter(hConsoleOutput, ' ', screen_buffer_info.dwSize.X * screen_buffer_info.dwSize.Y, Home, &dummy);
	screen_buffer_info.dwCursorPosition.X = 0;
	screen_buffer_info.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOutput, screen_buffer_info.dwCursorPosition);
}

//  Di chuyen con tro den cot x va hang y
void gotoXY(SHORT x, SHORT y)
{
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Show the x position.
SHORT wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.X;
}

// Show the y position.
SHORT wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.Y;
}

// Color Window;
void setColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Color background
void setBackgroundColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4; // Dich trai 3 bit de phu hop voi mau nen
	wAttributes &= 0xff0f; // Cai 0 cho 1 bit chu nhay va 3 bit mau nen
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void resizeText(int x, int y) {
	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, font);
	font->dwFontSize.X = x;
	font->dwFontSize.Y = y;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, font);
}

WORD textattr()
{
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	return ConsoleInfo.wAttributes;
}

void resettextattr()
{
	DWORD Mau_Mac_Dinh = textattr();
	SetConsoleTextAttribute(hConsoleOutput, Mau_Mac_Dinh);
}

//Ham in mau chu va thay doi mai nen hien thi theo vi tri x, y.
void setColorBGTextXY(SHORT x, SHORT y, WORD color, WORD background, LPSTR str, ...)
{
	gotoXY(x, y);
	setBackgroundColor(background);
	setColor(color);

	/*In duoc nhieu chu hon*/
	va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);
	/*In duoc nhieu chu hon*/

	resettextattr();
	//setColor(7);
}

//Show the cursor.
void Cursor(BOOL bVisible, DWORD dwSize)
{
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.bVisible = bVisible;
	ConsoleCursorInfo.dwSize = dwSize; // Phan tram bao trum o cua con tro chuot
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

// Delete number of rows, SStartPos - Row start; SNumberRow: Number of rows.
void deleteRow(SHORT SStartPos, SHORT SNumberRow)
{
	CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
	COORD Pos = { 0, SStartPos };
	DWORD Tmp;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	FillConsoleOutputCharacter(hConsoleOutput, ' ', ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	FillConsoleOutputAttribute(hConsoleOutput, 15, ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	SetConsoleCursorPosition(hConsoleOutput, Pos);
}

