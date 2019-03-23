#pragma once
#include "pch.h"
#include <iostream>

typedef struct cubik {
	int position;
	int col;
}cubik;
class cube
{
	
public:
	cubik arr[6][3][3];
	cube();
	~cube();
	void rotate_white();
	void rotate_yellow();
	void rotate_blue();
	void rotate_red();
	void rotate_green();
	void rotate_purple();
	void rotate_x(int row);
	void rotate_y(int row);
	void rotate_z(int row);
	void rotate_matrix(int face);


	void rotate_whitei();
	void rotate_yellowi();
	void rotate_bluei();
	void rotate_redi();
	void rotate_greeni();
	void rotate_purplei();
	void rotate_xi(int row);
	void rotate_yi(int row);
	void rotate_zi(int row);
	void rotate_matrixi(int face);

	void print();
	void rotate(int face, std::string c);
	void rotatei(int face, std::string c);
};

