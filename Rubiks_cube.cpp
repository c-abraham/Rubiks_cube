// Rubiks_cube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cube.h"
#include <time.h>
#include "white_cross.h"
#include "white_corners.h"
#include "second_layer.h"
#include "yellow_cross.h"
#include "yellow_corners.h"
#include <string>
#include "windows.h"

using namespace std;
typedef void(cube::*p)();
void Col(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
void shuffle(cube &c) {

	srand(time(NULL));
	p asdf[] = { &cube::rotate_yellow, &cube::rotate_white, &cube::rotate_blue,
				 &cube::rotate_red, &cube::rotate_green, &cube::rotate_purple ,
				 &cube::rotate_x, &cube::rotate_z, &cube::rotate_y};
	for (int i = 0; i < 100; i++)
		(c.*asdf[rand() % 9])();
}
void print_directions()
{
	std::cout << "Commands: \n"; Col(9);
	std::cout << "b, bi "; Col(7); std::cout << " rotate "; Col(9); std::cout << "blue     "; Col(15);
	std::cout << "w, wi "; Col(7); std::cout << " rotate "; Col(15); std::cout << "white    "; Col(12);
	std::cout << "r, ri "; Col(7); std::cout << " rotate "; Col(12); std::cout << "red\n"; Col(14);
	std::cout << "y, yi "; Col(7); std::cout << " rotate "; Col(14); std::cout << "yellow   "; Col(10);
	std::cout << "g, gi "; Col(7); std::cout << " rotate "; Col(10); std::cout << "green    "; Col(13);
	std::cout << "p, pi "; Col(7); std::cout << " rotate "; Col(13); std::cout << "purple\n";
	Col(15); std::cout << "sh";  Col(7); std::cout << " to shuffle cube     ";
	Col(15); std::cout << "sl";  Col(7); std:: cout<< " to solve cube       ";
	Col(15); std::cout << "q";   Col(7); std::cout<< " to exit\n\n";
	std::cout << "input command: ";

}
int main()
{
	std::cout << "Welcome to the Interface :)\n";

	cube c;
	c.print();
	print_directions();
	
	std::string input;
	while (getline(cin,input)) {
		ClearScreen();
		if (input == "q") {
			break;
		}
		if (input == "y") {
			c.rotate_yellow();
		}

		if (input == "yi") {
			c.rotate_yellowi();
		}

		if (input == "w") {
			c.rotate_white();
		}
		if (input == "wi") {
			c.rotate_whitei();
		}
		if (input == "r") {
			c.rotate_red();
		}
		if (input == "ri") {
			c.rotate_redi();
		}
		if (input == "b") {
			c.rotate_blue();
		}
		if (input == "bi") {
			c.rotate_bluei();
		}
		if (input == "g") {
			c.rotate_green();
		}
		if (input == "gi") {
			c.rotate_greeni();
		}
		if (input == "p") {
			c.rotate_purple();
		}
		if (input == "pi") {
			c.rotate_purplei();
		}
		if (input == "x") {
			c.rotate_x();
		}
		if (input == "k") {
			c.rotate_y();
		}
		if (input == "z") {
			c.rotate_z();
		}

		if (input == "xi") {
			c.rotate_xi();
		}
		if (input == "ki") {
			c.rotate_yi();
		}
		if (input == "zi") {
			c.rotate_zi();
		}
		
		if (input == "sl") {
			std::cout << "solving cube\n";
			c.count = 0;
			white_cross(c);
			c.print();
			white_corners(c);
			c.print();
			second_layer(c);
			c.print();
			yellow_cross(c);
			c.print();
			yellow_corners(c);
			std::cout << "Solved the cube in " << c.count << " moves\n\n";
		}
		if (input == "sh") {
			shuffle(c);
			ClearScreen();
			std::cout << "shuffle\n";
		}
		c.print();
		print_directions();
	}
}
