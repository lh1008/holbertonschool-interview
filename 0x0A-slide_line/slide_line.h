#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>
#include <stdio.h>
#include <math.h>

#define SLIDE_LEFT 'L'
#define SLIDE_RIGHT 'R'

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
