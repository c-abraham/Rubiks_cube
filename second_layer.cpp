#include "pch.h"
#include "cube.h"
#include <iostream>

void right_algorithm(cube &c, int face) {
	//U R U' R' U' F' U F
	c.rotate_yellow();
	c.rotatei(face,"R");
	c.rotate_yellowi();
	c.rotatei(face, "R'");
	c.rotate_yellowi();
	c.rotatei(face, "F'");
	c.rotate_yellow();
	c.rotatei(face, "F");
}

void left_algorithm(cube &c, int face) {
	//U' L' U L U F U' F'
	c.rotate_yellowi();
	c.rotatei(face, "L'");
	c.rotate_yellow();
	c.rotatei(face, "L");
	c.rotate_yellow();
	c.rotatei(face, "F");
	c.rotate_yellowi();
	c.rotatei(face, "F'");
}

void wrong_orientation(cube &c, int face) {
	//U R U' R' U' F' U F U2 U R U' R' U' F' U F
	right_algorithm(c,face);
	c.rotate_yellow();
	c.rotate_yellow();
	right_algorithm(c, face);
}
bool check(cube &c) {
	for (int i = 0; i < 6; i++) {
		if (c.arr[i][0][1].col != c.arr[i][1][1].col) {
			left_algorithm(c, i);
			c.print();
			return false;
		}
		if (c.arr[i][2][1].col != c.arr[i][1][1].col) {
			right_algorithm(c, i);
			c.print();
			return false;
		}
		if (i == 0 || i == 2) {
			i++;
		}
	}
	return true;
}
void second_layer(cube &c) {
loop:
	int face;
	int pos;
	for (int i = 0; i < 6; i ++) {
		if ((c.arr[i][1][2].position == 1 || c.arr[i][1][2].position == 7) && c.arr[i][1][2].col != 14) {
			face = i;
			pos = c.arr[i][1][2].position;
			goto found;
		}
		if (i == 0 || i == 2) {
			i++;
		}
	}
	if (check(c)) {
		return;
	}
	goto loop;
found:
	while (c.arr[face%6][1][2].col != c.arr[face%6][1][1].col) {
		c.rotate_yellowi();
		face++;
		if (face%6 == 1 || face%6 == 3) {
			face++;
		}
	}
	c.print();
	if (pos == 1) {
		left_algorithm(c, face);
	}
	else {
		right_algorithm(c, face);
	}
	c.print();
	goto loop;
}
