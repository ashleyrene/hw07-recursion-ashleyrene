#ifndef GRID_TRAVERSAL_H
#define GRID_TRAVERSAL_H

typedef enum SquareType {
    WALL = '#',
    SPACE = '.',
    START = 's',
    END = 'e'
} SquareType;

typedef enum PathType {
    SOUTH = 's',
    EAST = 'e'
} PathType;

char** read_grid_from_file(const char* filename, int* rows, int* cols);
void free_grid(char **grid, int rows);
void lexicographically_smallest_path(char **grid, int rows, int cols);

#endif
