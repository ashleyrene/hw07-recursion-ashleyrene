#include <stdio.h>
#include <stdlib.h>
#include "grid_traversal.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    int rows, cols;
    char** grid = read_grid_from_file(argv[1], &rows, &cols);

    lexicographically_smallest_path(grid, rows, cols);

    free_grid(grid, rows);
    return 0;
}
