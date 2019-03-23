#include "pch.h"
#include "cube.h"
#include <iostream>
#include "yellow_corners.h"

void swap(cube &c, int face) {
	//U R U' L' U R' U' L
	c.rotate_yellow();
	c.rotatei(face,"R");
	c.rotate_yellowi();
	c.rotatei(face, "L'");
	c.rotate_yellow();
	c.rotatei(face, "R'");
	c.rotate_yellowi();
	c.rotatei(face, "L");
}

void final_algorithm(cube&c, int face) {
	//R' D' R D
	c.rotatei(face, "R'");
	c.rotate_whitei();
	c.rotatei(face, "R");
	c.rotate_white();
}
void reposition(cube &c, int face) {
	if (face != 5) {
		while (!((c.arr[3][0][2].position == 2 && c.arr[3][0][2].col == 14) ||
			(c.arr[0][0][2].position == 2 && c.arr[0][0][2].col == 14) ||
			(c.arr[5][2][2].position == 2 && c.arr[5][2][2].col == 14))) {
			swap(c, face);
			c.print();
		}
	}
	else {
		while (!((c.arr[3][0][0].position == 0 && c.arr[3][0][0].col == 14) ||
			(c.arr[2][0][2].position == 0 && c.arr[2][0][2].col == 14) ||
			(c.arr[0][2][2].position == 0 && c.arr[0][2][2].col == 14)) ){
			swap(c, face);
			c.print();
		}
	}

}
void solve(cube &c,int x, int y, int face) {
	int corners[4] = { 0,2,8,6 };

	for (int i = 0; i < 4; i++) {
		while (c.arr[3][x][y].col != 14) {
			final_algorithm(c, face);
		}
		c.print();
		c.rotate_yellow();
	}
}
void yellow_corners(cube &c) {
	loop:
	if ((c.arr[3][0][0].position == 0 && c.arr[3][0][0].col == 14) ||
		(c.arr[2][0][2].position == 0 && c.arr[2][0][2].col == 14) ||
		(c.arr[0][2][2].position == 0 && c.arr[0][2][2].col == 14)) {
		reposition(c, 0);

	}
	else if ((c.arr[3][0][2].position == 2 && c.arr[3][0][2].col == 14) ||
		(c.arr[0][0][2].position == 2 && c.arr[0][0][2].col == 14) ||
		(c.arr[5][2][2].position == 2 && c.arr[5][2][2].col == 14)) {
		reposition(c, 5);
	}
	else if ((c.arr[3][2][2].position == 8 && c.arr[3][2][2].col == 14) ||
		(c.arr[5][0][2].position == 8 && c.arr[5][0][2].col == 14) ||
		(c.arr[4][2][2].position == 8 && c.arr[4][2][2].col == 14)) {
		reposition(c, 4);
	}
	else if ((c.arr[3][2][0].position == 6 && c.arr[3][2][0].col == 14) ||
		(c.arr[4][0][2].position == 6 && c.arr[4][0][2].col == 14) ||
		(c.arr[2][2][2].position == 6 && c.arr[2][2][2].col == 14)) {
		reposition(c, 2);
	}
	else {
		swap(c, 0);
		c.print();
		goto loop;

	}
	if (c.arr[3][0][0].col != 14) {
		solve(c, 0,0,0);
	}
	else if (c.arr[3][0][2].col != 14) {
		solve(c, 0, 2, 5);
	}
	else if (c.arr[3][2][2].col != 14) {
		solve(c, 2, 2, 4);
	}
	else if (c.arr[3][2][0].col != 14) {
		solve(c, 2, 0, 2);
	}
	c.print();
	while (c.arr[1][0][0].position != 0)
		c.rotate_white();
	while (c.arr[3][0][0].position != 0)
		c.rotate_white();
}
