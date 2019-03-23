#include "pch.h"
#include "cube.h"
#include <iostream>
#include "windows.h"
#include <string>
using namespace std;
cubik arr[6][3][3];
cube::cube()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cubik temp;
				if (i == 0) 
					temp.col = 9;//blue
				if (i == 1)
					temp.col = 7;//white
				if (i == 2)
					temp.col = 4;//red
				if (i == 3)
					temp.col = 14;//yellow
				if (i == 4)
					temp.col = 2;//green
				if (i == 5)
					temp.col = 5;//purple
				temp.position = k + j * 3;
				arr[i][j][k] = temp;
			}
		}
	}
}

cube::~cube()
{
}
void cube::rotatei(int face, std::string c) {
	if (face == 0) {
		if (c == "L") {
			rotate_purple();
		}
		if (c == "L'") {
			rotate_purplei();
		}
		if (c == "R") {
			rotate_red();
		}
		if (c == "R'") {
			rotate_redi();
		}
		if (c == "F") {
			rotate_blue();
		}
		if (c == "F'") {
			rotate_bluei();
		}
	}

	if (face == 2) {
		if (c == "L") {
			rotate_blue();
		}
		if (c == "L'") {
			rotate_bluei();
		}
		if (c == "R") {
			rotate_green();
		}
		if (c == "R'") {
			rotate_greeni();
		}
		if (c == "F") {
			rotate_red();
		}
		if (c == "F'") {
			rotate_redi();
		}
	}

	if (face == 4) {
		if (c == "L") {
			rotate_red();
		}
		if (c == "L'") {
			rotate_redi();
		}
		if (c == "R") {
			rotate_purple();
		}
		if (c == "R'") {
			rotate_purplei();
		}
		if (c == "F") {
			rotate_green();
		}
		if (c == "F'") {
			rotate_greeni();
		}
	}

	if (face == 5) {
		if (c == "L") {
			rotate_green();
		}
		if (c == "L'") {
			rotate_greeni();
		}
		if (c == "R") {
			rotate_blue();
		}
		if (c == "R'") {
			rotate_bluei();
		}
		if (c == "F") {
			rotate_purple();
		}
		if (c == "F'") {
			rotate_purplei();
		}
	}
}
void cube::rotate(int face, std::string c) {
	if (face == 0) {
		if (c == "R") {
			rotate_purple();
		}
		if (c == "R'") {
			rotate_purplei();
		}
		if (c == "L") {
			rotate_red();
		}
		if (c == "L'") {
			rotate_redi();
		}
		if (c == "F") {
			rotate_blue();
		}
		if (c == "F'") {
			rotate_bluei();
		}
	}

	if (face == 2) {
		if (c == "R") {
			rotate_blue();
		}
		if (c == "R'") {
			rotate_bluei();
		}
		if (c == "L") {
			rotate_green();
		}
		if (c == "L'") {
			rotate_greeni();
		}
		if (c == "F") {
			rotate_red();
		}
		if (c == "F'") {
			rotate_redi();
		}
	}

	if (face == 4) {
		if (c == "R") {
			rotate_red();
		}
		if (c == "R'") {
			rotate_redi();
		}
		if (c == "L") {
			rotate_purple();
		}
		if (c == "L'") {
			rotate_purplei();
		}
		if (c == "F") {
			rotate_green();
		}
		if (c == "F'") {
			rotate_greeni();
		}
	}

	if (face == 5) {
		if (c == "R") {
			rotate_green();
		}
		if (c == "R'") {
			rotate_greeni();
		}
		if (c == "L") {
			rotate_blue();
		}
		if (c == "L'") {
			rotate_bluei();
		}
		if (c == "F") {
			rotate_purple();
		}
		if (c == "F'") {
			rotate_purplei();
		}
	}
}
void cube::rotate_white() {
	//implement queue to do this dynamically
	std::cout << "rotate white\n";
	cubik temp0 = arr[0][0][0];
	cubik temp1 = arr[0][1][0];
	cubik temp2 = arr[0][2][0];

	for (int i = 0; i < 3; i++) {
		arr[0][i][0] = arr[5][i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][i][0] = arr[4][i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][0] = arr[2][i][0];
	}

	arr[2][0][0] = temp0;
	arr[2][1][0] = temp1;
	arr[2][2][0] = temp2;
	rotate_matrix(1);

}

void cube::rotate_whitei() {
	std::cout << "rotate whitei\n";
	//implement queue to do this dynamically
	cubik temp0 = arr[0][0][0];
	cubik temp1 = arr[0][1][0];
	cubik temp2 = arr[0][2][0];

	for (int i = 0; i < 3; i++) {
		arr[0][i][0] = arr[2][i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[2][i][0] = arr[4][i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][0] = arr[5][i][0];
	}

	arr[5][0][0] = temp0;
	arr[5][1][0] = temp1;
	arr[5][2][0] = temp2;
	cubik temp = arr[1][0][0];
	rotate_matrixi(1);
}

void cube::rotate_yellow() {
	std::cout << "rotate yellow\n";
	cubik temp0 = arr[0][0][2];
	cubik temp1 = arr[0][1][2];
	cubik temp2 = arr[0][2][2];

	for (int i = 0; i < 3; i++) {
		arr[0][i][2] = arr[2][i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[2][i][2] = arr[4][i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][2] = arr[5][i][2];
	}

	arr[5][0][2] = temp0;
	arr[5][1][2] = temp1;
	arr[5][2][2] = temp2;
	cubik temp = arr[1][0][0];
	rotate_matrix(3);

}

void cube::rotate_yellowi() {
	std::cout << "rotate yellowi\n";
	cubik temp0 = arr[0][0][2];
	cubik temp1 = arr[0][1][2];
	cubik temp2 = arr[0][2][2];

	for (int i = 0; i < 3; i++) {
		arr[0][i][2] = arr[5][i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][i][2] = arr[4][i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][2] = arr[2][i][2];
	}

	arr[2][0][2] = temp0;
	arr[2][1][2] = temp1;
	arr[2][2][2] = temp2;
	cubik temp = arr[1][0][0];
	rotate_matrixi(3);
}

void cube::rotate_blue() {
	std::cout << "rotate blue\n";
	cubik temp0 = arr[5][2][0];
	cubik temp1 = arr[5][2][1];
	cubik temp2 = arr[5][2][2];

	for (int i = 0; i < 3; i++) {
		arr[5][2][i] = arr[1][0][2-i];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][0][i] = arr[2][0][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[2][0][i] = arr[3][0][i];
	}

	arr[3][0][2] = temp0;
	arr[3][0][1] = temp1;
	arr[3][0][0] = temp2;
	rotate_matrix(0);
}

void cube::rotate_bluei() {
	std::cout << "rotate bluei\n";
	cubik temp0 = arr[5][2][0];
	cubik temp1 = arr[5][2][1];
	cubik temp2 = arr[5][2][2];

	for (int i = 0; i < 3; i++) {
		arr[5][2][i] = arr[3][0][2 - i];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][0][i] = arr[2][0][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[2][0][i] = arr[1][0][i];
	}

	arr[1][0][2] = temp0;
	arr[1][0][1] = temp1;
	arr[1][0][0] = temp2;
	rotate_matrixi(0);
}

void cube::rotate_red() {
	std::cout << "rotate red\n";
	cubik temp0 = arr[0][2][0];
	cubik temp1 = arr[0][2][1];
	cubik temp2 = arr[0][2][2];

	for (int i = 0; i < 3; i++) {
		arr[0][2][i] = arr[1][2-i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][i][2] = arr[4][0][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][0][2-i] = arr[3][i][0];
	}

	arr[3][0][0] = temp0;
	arr[3][1][0] = temp1;
	arr[3][2][0] = temp2;
	rotate_matrix(2);
}
void cube::rotate_redi() {
	std::cout << "rotate redi\n";
	cubik temp0 = arr[0][2][0];
	cubik temp1 = arr[0][2][1];
	cubik temp2 = arr[0][2][2];

	for (int i = 0; i < 3; i++) {
		arr[0][2][i] = arr[3][i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][i][0] = arr[4][0][2-i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][0][i] = arr[1][i][2];
	}

	arr[1][2][2] = temp0;
	arr[1][1][2] = temp1;
	arr[1][0][2] = temp2;
	rotate_matrixi(2);
}

void cube::rotate_green() {
	std::cout << "rotate green\n";
	cubik temp0 = arr[2][2][0];
	cubik temp1 = arr[2][2][1];
	cubik temp2 = arr[2][2][2];

	for (int i = 0; i < 3; i++) {
		arr[2][2][i] = arr[1][2][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][2][i] = arr[5][0][2-i];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][0][2 - i] = arr[3][2][i];
	}

	arr[3][2][0] = temp0;
	arr[3][2][1] = temp1;
	arr[3][2][2] = temp2;
	rotate_matrix(4);
}

void cube::rotate_greeni() {
	std::cout << "rotate greeni\n";
	cubik temp0 = arr[2][2][0];
	cubik temp1 = arr[2][2][1];
	cubik temp2 = arr[2][2][2];

	for (int i = 0; i < 3; i++) {
		arr[2][2][i] = arr[3][2][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][2][i] = arr[5][0][2-i];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][0][2 - i] = arr[1][2][i];
	}

	arr[1][2][0] = temp0;
	arr[1][2][1] = temp1;
	arr[1][2][2] = temp2;
	rotate_matrixi(4);
}

void cube::rotate_purple() {
	std::cout << "rotate purple\n";
	cubik temp0 = arr[0][0][0];
	cubik temp1 = arr[0][0][1];
	cubik temp2 = arr[0][0][2];

	for (int i = 0; i < 3; i++) {
		arr[0][0][i] = arr[3][i][2];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][i][2] = arr[4][2][2-i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][2][i] = arr[1][i][0];
	}

	arr[1][2][0] = temp0;
	arr[1][1][0] = temp1;
	arr[1][0][0] = temp2;
	rotate_matrix(5);
}

void cube::rotate_purplei() {
	std::cout << "rotate purplei\n";
	cubik temp0 = arr[0][0][0];
	cubik temp1 = arr[0][0][1];
	cubik temp2 = arr[0][0][2];

	for (int i = 0; i < 3; i++) {
		arr[0][0][i] = arr[1][2 - i][0];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][i][0] = arr[4][2][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][2][2 - i] = arr[3][i][2];
	}

	arr[3][0][2] = temp0;
	arr[3][1][2] = temp1;
	arr[3][2][2] = temp2;
	rotate_matrixi(5);
}
void cube::rotate_x(int row) {
	cubik temp0 = arr[2][1][0];
	cubik temp1 = arr[2][1][1];
	cubik temp2 = arr[2][1][2];

	for (int i = 0; i < 3; i++) {
		arr[2][1][i] = arr[1][1][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][1][i] = arr[5][1][2 - i];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][1][2 - i] = arr[3][1][i];
	}

	arr[3][1][0] = temp0;
	arr[3][1][1] = temp1;
	arr[3][1][2] = temp2;

}

void cube::rotate_xi(int row) {
	cubik temp0 = arr[2][1][0];
	cubik temp1 = arr[2][1][1];
	cubik temp2 = arr[2][1][2];

	for (int i = 0; i < 3; i++) {
		arr[2][1][i] = arr[3][1][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][1][i] = arr[5][1][2 - i];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][1][2 - i] = arr[1][1][i];
	}

	arr[1][1][0] = temp0;
	arr[1][1][1] = temp1;
	arr[1][1][2] = temp2;
}
void cube::rotate_y(int row) {
	//implement queue to do this dynamically
	cubik temp0 = arr[0][0][row];
	cubik temp1 = arr[0][1][row];
	cubik temp2 = arr[0][2][row];

	for (int i = 0; i < 3; i++) {
		arr[0][i][row] = arr[5][i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[5][i][row] = arr[4][i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][row] = arr[2][i][row];
	}

	arr[2][0][row] = temp0;
	arr[2][1][row] = temp1;
	arr[2][2][row] = temp2;

}
void cube::rotate_yi(int row) {
	cubik temp0 = arr[0][0][row];
	cubik temp1 = arr[0][1][row];
	cubik temp2 = arr[0][2][row];

	for (int i = 0; i < 3; i++) {
		arr[0][i][row] = arr[2][i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[2][i][row] = arr[4][i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][i][row] = arr[5][i][row];
	}

	arr[5][0][row] = temp0;
	arr[5][1][row] = temp1;
	arr[5][2][row] = temp2;
}


void cube::rotate_z(int row) {
	cubik temp0 = arr[0][row][0];
	cubik temp1 = arr[0][row][1];
	cubik temp2 = arr[0][row][2];

	for (int i = 0; i < 3; i++) {
		arr[0][row][i] = arr[3][2 - i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[3][i][row] = arr[4][row][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][row][2 - i] = arr[1][i][row];
	}

	arr[1][0][row] = temp0;
	arr[1][1][row] = temp1;
	arr[1][2][row] = temp2;
}
void cube::rotate_zi(int row) {
	cubik temp0 = arr[0][row][0];
	cubik temp1 = arr[0][row][1];
	cubik temp2 = arr[0][row][2];

	for (int i = 0; i < 3; i++) {
		arr[0][row][i] = arr[1][2 - i][row];
	}

	for (int i = 0; i < 3; i++) {
		arr[1][i][row] = arr[4][row][i];
	}

	for (int i = 0; i < 3; i++) {
		arr[4][row][2 - i] = arr[3][i][row];
	}

	arr[3][0][row] = temp0;
	arr[3][1][row] = temp1;
	arr[3][2][row] = temp2;

}
//https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
void cube::rotate_matrixi(int face) {
	int N = 3;
	// Consider all squares one by one 
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in  
		// current square 
		for (int y = x; y < N - x - 1; y++)
		{
			// store current cell in temp variable 
			cubik temp = arr[face][x][y];

			// move values from right to top 
			arr[face][x][y] = arr[face][y][N - 1 - x];

			// move values from bottom to right 
			arr[face][y][N - 1 - x] = arr[face][N - 1 - x][N - 1 - y];

			// move values from left to bottom 
			arr[face][N - 1 - x][N - 1 - y] = arr[face][N - 1 - y][x];

			// assign temp to left 
			arr[face][N - 1 - y][x] = temp;
		}
	}
}

void cube::rotate_matrix(int face) {
	int N = 3;
	// Consider all squares one by one 
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in  
		// current square 
		for (int y = x; y < N - x - 1; y++)
		{
			// store current cell in temp variable 
			cubik temp = arr[face][x][y];
			arr[face][x][y] = arr[face][N - 1 - y][x];
			arr[face][N - 1 - y][x] = arr[face][N - 1 - x][N - 1 - y];
			arr[face][N - 1 - x][N - 1 - y] = arr[face][y][N - 1 - x];
			arr[face][y][N - 1 - x] = temp;
		}
	}
}
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void cube::print() {
	for (int i = 0; i < 3; i++) {
		
		std::cout << "      ";
		SetColor(arr[0][i][0].col); std::cout << arr[0][i][0].position << " ";
		SetColor(arr[0][i][1].col); std::cout << arr[0][i][1].position << " ";
		SetColor(arr[0][i][2].col); std::cout << arr[0][i][2].position << " ";
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++) {
		SetColor(arr[1][i][0].col); std::cout << arr[1][i][0].position << " ";
		SetColor(arr[1][i][1].col); std::cout << arr[1][i][1].position << " ";
		SetColor(arr[1][i][2].col); std::cout << arr[1][i][2].position << " ";
		SetColor(arr[2][i][0].col); std::cout << arr[2][i][0].position << " ";
		SetColor(arr[2][i][1].col); std::cout << arr[2][i][1].position << " ";
		SetColor(arr[2][i][2].col); std::cout << arr[2][i][2].position << " ";
		SetColor(arr[3][i][0].col); std::cout << arr[3][i][0].position << " ";
		SetColor(arr[3][i][1].col); std::cout << arr[3][i][1].position << " ";
		SetColor(arr[3][i][2].col); std::cout << arr[3][i][2].position << " ";
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++) {
		std::cout << "      ";
		SetColor(arr[4][i][0].col); std::cout << arr[4][i][0].position << " ";
		SetColor(arr[4][i][1].col); std::cout << arr[4][i][1].position << " ";
		SetColor(arr[4][i][2].col); std::cout << arr[4][i][2].position << " ";
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++) {
		std::cout << "      ";
		SetColor(arr[5][i][0].col); std::cout << arr[5][i][0].position << " ";
		SetColor(arr[5][i][1].col); std::cout << arr[5][i][1].position << " ";
		SetColor(arr[5][i][2].col); std::cout << arr[5][i][2].position << " ";
		std::cout << std::endl;
	}
	SetColor(7);
	std::cout << std::endl;
}
