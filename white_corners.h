#pragma once
#include "pch.h"
#include "cube.h"
#include <iostream>
void white_corners(cube &c);
int * find_piece(cube &c, int pos);
void right(cube &c, int face);
void front(cube &c, int face);
void bottom(cube &c, int position);
void rotation(cube &c, int face, int position, int val);
void change_pos(cube &c, int position, int val);
void change_pos(cube &c, int face, int position, int val);

