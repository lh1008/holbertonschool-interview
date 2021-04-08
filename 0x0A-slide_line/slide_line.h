#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>
#include <stdio.h>
#include <math.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void swap_integers(int *n, int *n2);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

#endif /* SLIDE_LINE_H */
