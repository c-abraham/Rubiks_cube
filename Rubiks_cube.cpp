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

using namespace std;
typedef void(cube::*p)();
void shuffle(cube &c) {

	srand(time(NULL));
	p asdf[] = { &cube::rotate_yellow, &cube::rotate_white, &cube::rotate_blue,
							&cube::rotate_red, &cube::rotate_green, &cube::rotate_purple };
	for (int i = 0; i < 100; i++)
		(c.*asdf[rand() % 6])();
}
int main()
{
	std::string input;
	cube c;
	c.print();
	
	while (getline(cin,input)) {

		if (input == "q") {
			break;
		}
		if (input == "y") {
			c.rotate_yellow();
			c.print();
		}

		if (input == "yi") {
			c.rotate_yellowi();
			c.print();
		}

		if (input == "w") {
			c.rotate_white();
			c.print();
		}
		if (input == "wi") {
			c.rotate_whitei();
			c.print();
		}
		if (input == "r") {
			c.rotate_red();
			c.print();
		}
		if (input == "ri") {
			c.rotate_redi();
			c.print();
		}
		if (input == "b") {
			c.rotate_blue();
			c.print();
		}
		if (input == "bi") {
			c.rotate_bluei();
			c.print();
		}
		if (input == "g") {
			c.rotate_green();
			c.print();
		}
		if (input == "gi") {
			c.rotate_greeni();
			c.print();
		}
		if (input == "p") {
			c.rotate_purple();
			c.print();
		}
		if (input == "pi") {
			c.rotate_purplei();
			c.print();
		}
		
		if (input == "solve") {
			white_cross(c);
			c.print();
			white_corners(c);
			c.print();
			second_layer(c);
			c.print();
			yellow_cross(c);
			c.print();
			yellow_corners(c);
			c.print();
		}
		if (input == "shuffle") {
			shuffle(c);
			c.print();
		}
		if (input == "test") {
			c.rotate_greeni();
			c.rotate_yellow();
			c.rotate_green();
		}
		
	}
	
	//swap_edges(c, 0);
	//swap_edges(c, 2);
	//c.print();
	
	//swap(c, 0);
	//c.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
