#pragma once
#include "pch.h"
#include "cube.h"
#include <iostream>
void right_algorithm(cube &c, int face);
void left_algorithm(cube &c, int face);
void wrong_orientation(cube &c, int face);
bool check(cube &c);
void second_layer(cube &c);
