#include "pch.h"
#include "cube.h"
#include <iostream>

void white_top(cube &c,int center) {
	//fi(< ), u(< ), l'(^), ui(> )
	if (center == 3) {
		c.rotate_red();
		c.rotate_red();
	}
	else {
		c.rotate(center, "F'");
		c.rotate_white();
		c.rotate(center, "L'");
		c.rotate_whitei();
	}
}
void white_right(cube &c, int center) {
	if (center == 3) {
		c.rotate_yellowi();
		c.rotate_red();
		c.rotate_red();
	}
	else {
		c.rotate_whitei();
		c.rotate(center, "R");
		c.rotate_white();
	}
}
void white_bottom(cube &c, int center) {
	//fi, ui, r, u
	if (center == 3) {
		c.rotate_yellow();
		c.rotate_yellow();
		c.rotate_red();
		c.rotate_red();
	}
	else {
		c.rotate(center, "F'");
		white_right(c, center);
	}
}

void white_left(cube &c, int center) {
	if (center == 3) {
		c.rotate_yellow();
		c.rotate_red();
		c.rotate_red();
	}
	else {
		c.rotate_white();
		c.rotate(center, "L'");
		c.rotate_whitei();
	}
}

int * find_piece(cube &c, int pos) {
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
void position_piece(cube &c, int face, int x, int y) {
	if (x == 0)
		white_right(c, face);
	else if (x == 1 && y == 0)
		white_top(c, face);
	else if (x == 1 && y == 2)
		white_bottom(c, face);
	else
		white_left(c, face);

}
void repositions_top(cube &c, int face,int val) {
	if (face == 0) {
		while (!((c.arr[1][1][0].position == val) && (c.arr[1][1][0].col==7))) {
			c.rotate_white();
		}
	}
	else if (face == 2||face ==3) {

		while (!((c.arr[1][0][1].position == val) && (c.arr[1][0][1].col == 7) )){
			c.rotate_white();
		}
	}
	else if (face == 4) {
		while (!((c.arr[1][1][2].position == val) && (c.arr[1][1][2].col == 7)) ){
			c.rotate_white();
		}
	}
	else if (face == 5) {
		while (!((c.arr[1][2][1].position == val )&& (c.arr[1][2][1].col == 7))) {
			c.rotate_white();
		}
	}
	
}
void check_top(cube &c, int x, int y,int val) {
	if (x == 0&&y==1) {
		if (!((c.arr[1][1][0].position == val) && (c.arr[1][1][0].col == 7))) {
			c.rotate_blue();
			repositions_top(c, 0, val);
			c.rotate_bluei();
		}
	}
	else if (x == 1 && y == 2) {

		if (!((c.arr[1][0][1].position == val) && (c.arr[1][0][1].col == 7))) {
			c.rotate_red();
			repositions_top(c, 2, val);
			c.rotate_redi();
		}
	}
	else if (x == 2 && y == 1) {
		if (!((c.arr[1][1][2].position == val) && (c.arr[1][1][2].col == 7))) {
			c.rotate_green();
			repositions_top(c, 4, val);
			c.rotate_greeni();
		}
	}
	else if (x == 1 && y == 0) {
		if (!((c.arr[1][2][1].position == val) && (c.arr[1][2][1].col == 7))) {
			c.rotate_purple();
			repositions_top(c, 5, val);
			c.rotate_purplei();
		}
	}
}
void reposistion(cube &c, int face,int val) {
	if( face == 0){
		c.rotate_blue();
		repositions_top(c, 0, val);
		position_piece(c, 0, 0, 1);

	}
	if (face == 2) {
		c.rotate_red();
		repositions_top(c, 2, val);
		position_piece(c, 2, 0, 1);
	}
	if (face == 4) {
		c.rotate_green();
		repositions_top(c, 4, val);
		position_piece(c, 4, 0, 1);
	}
	if (face == 5) {
		c.rotate_purple();
		repositions_top(c, 5, val);
		position_piece(c, 5, 0, 1);
	}

}
void white_cross(cube &c) {
	int * top;
	int * right;
	int * bottom;
	int * left;
	int a; int b; int d;
	//solve white 3
	top = find_piece(c, 3);
	a = *(top + 0);
	b = *(top + 1);
	d = *(top + 2);
	if (a != 1)
		position_piece(c, a, b, d);
	//solve white 1
	c.print();
	right = find_piece(c, 1);
	a = *(right + 0);
	b = *(right + 1);
	d = *(right + 2);
	if (a == 1) {
		check_top(c, b, d, 3);
		
	}
	else if (d == 0 && a != 3) {
		reposistion(c, a,3);
	}
	else
	{
		repositions_top(c, a, 3);
		position_piece(c, a, b, d);
	}
	//solve white 5
	c.print();
	bottom = find_piece(c, 5);
	a = *(bottom + 0);
	b = *(bottom + 1);
	d = *(bottom + 2);
	if (a == 1) {
		check_top(c, b, d, 1);
	}
	else if (d == 0 && a != 3) {
		reposistion(c, a, 1);
	}
	else {
		repositions_top(c, a, 1);
		position_piece(c, a, b, d);
	}
	//solve white 7
	c.print();
	left = find_piece(c, 7);
	a = *(left + 0);
	b = *(left + 1);
	d = *(left + 2);
	if (a == 1) {
		check_top(c, b, d, 5);
	}
	else if (d == 0 && a != 3) {
		reposistion(c, a, 5);
	}
	else {
		repositions_top(c, a, 5);
		position_piece(c, a, b, d);
	}
	c.print();

}
