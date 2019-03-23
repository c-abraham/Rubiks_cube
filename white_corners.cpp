#include "pch.h"
#include "cube.h"
#include <iostream>

int * find_pieces(cube &c, int pos) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (c.arr[i][j][k].col == 7 && c.arr[i][j][k].position == pos) {
					int r[3] = { i, j, k };
					return r;
				}
			}
		}
	}
	return NULL;
}
int *find_position(cube c, int x, int y) {
	if (c.arr[1][1][0].position == x && c.arr[1][0][1].position == y) {
		int a[2] = { 0,0 };
		return a;
	}
	else if (c.arr[1][0][1].position == x && c.arr[1][1][2].position == y) {
		int a[2] = { 0,2 };
		return a;
	}
	else if (c.arr[1][1][2].position == x && c.arr[1][2][1].position == y) {
		int a[2] = { 2,2 };
		return a;
	}
	int a[2] = { 2,0 };
	return a;
}
void right(cube &c, int face) {
	//R' D' R
	c.rotate(face, "R'");
	c.rotate_yellowi();
	c.rotate(face, "R");
}

void front(cube &c, int face) {
	//F D F'
	c.rotate(face, "F");
	c.rotate_yellow();
	c.rotate(face, "F'");
}
void bottom(cube &c, int position) {
	//R' D2 R D R' D' R
	int face;
	if (position == 0) {
		face = 2;
	}
	if (position == 2) {
		face = 0;
	}
	if (position == 6) {
		face = 4;
	}
	if (position == 8) {
		face = 5;
	}
	c.rotate(face,"R'");
	c.rotate_yellow();
	c.rotate_yellow();
	c.rotate(face, "R");
	c.rotate_yellow();
	c.rotate(face, "R'");
	c.rotate_yellowi();
	c.rotate(face, "R");
}
void rotation(cube &c, int face, int position,int val) {
	if ((face == 0 && position == 2 )||(face == 5 && position == 8)) {
		while (!((c.arr[1][1][0].position == val) && (c.arr[1][1][0].col == 7))) {
			c.rotate_white();
		}
		if (face == 0)
			front(c, 0);
		else
			right(c, 0);
	}
	else if (face == 3 && position == 2){
		while (!((c.arr[1][1][0].position == val) && (c.arr[1][1][0].col == 7))) {
			c.rotate_white();
		}
		bottom(c, position);
	}


	else if ((face == 0 && position == 8) || (face == 2 && position == 2)) {
		while (!((c.arr[1][0][1].position == val) && (c.arr[1][0][1].col == 7))) {
			c.rotate_white();
		}
		if (face == 0)
			right(c, 2);
		else
			front(c, 2);
	}
	else if (face == 3 && position == 0) {
		while (!((c.arr[1][0][1].position == val) && (c.arr[1][0][1].col == 7))) {
			c.rotate_white();
		}	
		bottom(c, position);
	}


	else if ((face == 2 && position == 8) || (face == 4 && position == 2)) {
		while (!((c.arr[1][1][2].position == val) && (c.arr[1][1][2].col == 7))) {
			c.rotate_white();
		}
		if (face == 2)
			right(c, 4);
		else
			front(c, 4);
	}
	else if (face == 3 && position == 6) {
		while (!((c.arr[1][1][2].position == val) && (c.arr[1][1][2].col == 7))) {
			c.rotate_white();
		}
		bottom(c, position);
	}


	else if ((face == 4 && position == 8) || (face == 5 && position == 2)) {
		while (!((c.arr[1][2][1].position == val) && (c.arr[1][2][1].col == 7))) {
			c.rotate_white();
		}
		if (face == 4)
			right(c, 5);
		else
			front(c, 5);
	}
	else if (face == 3 && position == 8) {
		while (!((c.arr[1][2][1].position == val) && (c.arr[1][2][1].col == 7))) {
			c.rotate_white();
		}
		bottom(c, position);
	}
	c.print();
}

void change_pos(cube &c, int position, int val) {
	if (position == 0) {
		c.rotate_blue();
		c.rotate_yellowi();
		c.rotate_bluei();
		rotation(c, 0, 2, val);
	}
	if (position == 2) {
		c.rotate_bluei();
		c.rotate_yellow();
		c.rotate_blue();
		rotation(c, 0, 8, val);
	}
	if (position == 6) {
		c.rotate_greeni();
		c.rotate_yellow();
		c.rotate_green();
		rotation(c, 4, 8, val);
	}
	if (position == 8) {
		c.rotate_green();
		c.rotate_yellowi();
		c.rotate_greeni();
		rotation(c, 4, 2, val);
	}
}

void change_pos(cube &c, int face,int position, int val) {
	
	if (face == 0 && position == 0) {
		c.rotate_blue();
		c.rotate_yellowi();
		c.rotate_bluei();
		rotation(c, 3, 2, val);
		
	}
	if (face == 0 && position == 6) {
		c.rotate_bluei();
		c.rotate_yellow();
		c.rotate_blue();
		rotation(c, 3, 0, val);
		
	}

	if (face == 2 && position == 0) {
		c.rotate_red();
		c.rotate_yellowi();
		c.rotate_redi();
		rotation(c, 3, 0, val);
		
	}
	if (face == 2 && position == 6) {
		c.rotate_redi();
		c.rotate_yellow();
		c.rotate_red();
		rotation(c, 3, 6, val);
		
	}

	if (face == 4 && position == 0) {
		c.rotate_green();
		c.rotate_yellowi();
		c.rotate_greeni();
		rotation(c, 3, 6, val);
		
	}
	if (face == 4 && position == 6) {
		c.rotate_greeni();
		c.rotate_yellow();
		c.rotate_green();
		rotation(c, 3, 8, val);
		
	}

	if (face == 5 && position == 0) {
		c.rotate_purple();
		c.rotate_yellowi();
		c.rotate_purplei();
		rotation(c, 3, 8, val);
	}
	if (face == 5 && position == 6) {
		c.rotate_purplei();
		c.rotate_yellow();
		c.rotate_purple();
		rotation(c, 3, 2, val);
		
	}
}

void white_corners(cube &c) {
	int * tl;
	int * tr;
	int * bl;
	int * br;
	int  *pos;
	int x; int y;
	int a; int b; int d;
	//top left corner (between 1 and 3)
	tl = find_pieces(c, 0);
	a = *(tl+0);
	b = *(tl + 1);
	d = *(tl + 2);
	pos=find_position(c, 3, 1);
	x = *(pos + 0);
	y = *(pos + 1);
	if (!(c.arr[1][x][y].position == 0 && c.arr[1][x][y].col == 7)) {
		if (a == 1) {
			change_pos(c, b * 3 + d, 3);
		}
		else if (d == 0 && a != 3) {
			change_pos(c,a, b * 3 + d, 3);
		}
		else {
			rotation(c, a, b * 3 + d,3);
			//apply algorithm
		}
	}

	//find corner 2
	tr = find_pieces(c, 2);
	a = *(tr + 0);
	b = *(tr + 1);
	d = *(tr + 2);
	pos = find_position(c, 1, 5);
	x = *(pos + 0);
	y = *(pos + 1);
	if (!(c.arr[1][x][y].position == 2 && c.arr[1][x][y].col == 7)) {
		if (a == 1) {
			change_pos(c, b * 3 + d, 1);
		}
		else if (d == 0 && a != 3) {
			change_pos(c, a, b * 3 + d, 1);
		}
		else {
			rotation(c, a, b * 3 + d, 1);
			//apply algorithm
		}
	}

	//find bottom right
	br = find_pieces(c, 8);
	a = *(br + 0);
	b = *(br + 1);
	d = *(br + 2);
	pos = find_position(c, 5, 7);
	x = *(pos + 0);
	y = *(pos + 1);
	if (!(c.arr[1][x][y].position == 8 && c.arr[1][x][y].col == 7)) {
		if (a == 1) {
			change_pos(c, b * 3 + d, 5);
		}
		else if (d == 0 && a != 3) {
			change_pos(c, a, b * 3 + d, 5);
		}
		else {
			rotation(c, a, b * 3 + d, 5);
			//apply algorithm
		}
	}

	//find corner 7
	bl = find_pieces(c, 6);
	a = *(bl + 0);
	b = *(bl + 1);
	d = *(bl + 2);
	pos = find_position(c, 7, 3);
	x = *(pos + 0);
	y = *(pos + 1);
	if (!(c.arr[1][x][y].position == 6 && c.arr[1][x][y].col == 7)) {
		if (a == 1) {
			change_pos(c, b * 3 + d, 7);
		}
		else if (d == 0 && a != 3) {
			change_pos(c, a, b * 3 + d, 7);
		}
		else {
			rotation(c, a, b * 3 + d, 7);
			//apply algorithm
		}
	}
	while (c.arr[1][0][0].position != 0)
		c.rotate_white();
}