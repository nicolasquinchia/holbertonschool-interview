
#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 76
#define SLIDE_RIGHT 82

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif /* SLIDE_H */
