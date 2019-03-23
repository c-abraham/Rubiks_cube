#pragma once
#include "pch.h"
#include "cube.h"
#include <iostream>
void yellow_cross(cube &c);
bool check_cross(cube &c);
bool check_line(cube &c);
bool check_L(cube &c);
void make_cross(cube&c, int face);
void swap_edges(cube &c, int face);