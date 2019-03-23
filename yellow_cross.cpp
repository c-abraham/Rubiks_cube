#include "pch.h"
#include "cube.h"
#include <iostream>
#include "yellow_cross.h"

void make_cross(cube&c, int face) {
	//F R U R' U' F'
	c.rotatei(face, "F");
	c.rotatei(face, "R");
	c.rotate_yellow();
	c.rotatei(face, "R'");
	c.rotate_yellowi();
	c.rotatei(face, "F'");
}
void l_cross(cube&c, int face) {
	//F U R U' R' F'
	c.rotatei(face, "F");
	c.rotate_yellow();
	c.rotatei(face, "R");
	c.rotate_yellowi();
	c.rotatei(face, "R'");
	c.rotatei(face, "F'");
}
bool check_L(cube &c) {
	if (c.arr[3][1][0].col == 14 && c.arr[3][0][1].col == 14) {
		l_cross(c, 4);
		return true;
	}
	if (c.arr[3][0][1].col == 14 && c.arr[3][1][2].col == 14) {
		l_cross(c, 2);
		return true;
	}
	if (c.arr[3][1][2].col == 14 && c.arr[3][2][1].col == 14) {
		l_cross(c, 0);
		return true;
	}
	if (c.arr[3][2][1].col == 14 && c.arr[3][1][0].col == 14) {
		l_cross(c, 5);
		return true;
	}
	return false;
}
bool check_line(cube &c) {
	if (c.arr[3][1][0].col == 14 && c.arr[3][1][2].col == 14) {
		make_cross(c, 4);
		return true;
	}
	if (c.arr[3][0][1].col == 14 && c.arr[3][2][1].col == 14) {
		make_cross(c, 2);
		return true;
	}
	return false;
}
bool check_cross(cube &c) {
	if (c.arr[3][1][0].col == 14 && c.arr[3][0][1].col == 14 &&
		c.arr[3][1][2].col == 14 && c.arr[3][1][2].col == 14)
		return true;
	return false;
}
void swap_edges(cube &c,int face) {
	//R U R' U R U2 R' U
	c.rotatei(face, "R");
	c.rotate_yellow();
	c.rotatei(face, "R'");
	c.rotate_yellow();
	c.rotatei(face, "R");
	c.rotate_yellow();
	c.rotate_yellow();
	c.rotatei(face, "R'");
	c.rotate_yellow();
}
void yellow_cross(cube &c) {
	//check if l shape
	while (!(check_cross(c))) {
		if (!check_L(c)) {
			if (!check_line(c)) {
				make_cross(c,0);
			}
		}
	}
	c.print();
	//position edge 3 in its spot
	if (c.arr[3][0][1].position == 3)
		swap_edges(c, 2);
	else if (c.arr[3][2][1].position == 3) {
		swap_edges(c, 4);
	}
	else if (c.arr[3][1][2].position == 3) {
		swap_edges(c, 0);
		swap_edges(c, 2);
	}
	//position edge 1
	c.print();
	if (c.arr[3][1][2].position == 1) {
		swap_edges(c, 0);
	}
	else if (c.arr[3][2][1].position == 1) {
		swap_edges(c, 5);
		swap_edges(c, 0);
	}
	//position edge 5
	if (c.arr[3][2][1].position == 5) {
		swap_edges(c, 5);
	}
	c.print();
}