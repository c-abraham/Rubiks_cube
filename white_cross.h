#pragma once
#include "pch.h"
#include "cube.h"
#include <iostream>
void white_top(cube &c, int center);
void white_right(cube &c, int center);
void white_left(cube &c, int center);
void white_bottom(cube &c, int center);
int * find_piece(cube &c, int pos);
void position_piece(cube &c, int face, int x, int y);
void white_cross(cube &c);
