#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void grid_add(int grid1[3][3], int grid2[3][3]);
void print_(int grid[3][3]);
int check_grid(int grid[3][3]);
void change_value(int grid1[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
