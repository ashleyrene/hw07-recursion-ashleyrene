#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid_traversal.h"

char** read_grid_from_file(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file");
        return NULL;
    }

    fscanf(file, "%d %d", rows, cols);

    // Allocate memory for the grid
    char** grid = (char**)malloc(*rows * sizeof(char*));
    if (!grid) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }
    
    // Allocate memory for each row
    for (int i = 0; i < *rows; i++) {
        grid[i] = (char*)malloc(*cols * sizeof(char));
        if (!grid[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int j = 0; j < i; j++) free(grid[j]);
            free(grid);
            fclose(file);
            return NULL;
        }
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, " %c", &grid[i][j]);
        }
    }

    fclose(file);
    return grid;
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);c
    }
    free(grid);
}

bool lexicographically_smallest_path_util(char **grid, int rows, int cols, int x, int y, char* path, int pos) {

    // First write your base case : If the destination is reached return an appriopriate value
    if (grid[x][y] == END) {
        path[pos] = '\0'; // Null-terminate the path string
        printf("%s\n", path);
        return true;
    }
    //iff out of bounds or hitting a wall, return false
    if (x >= rows || y >= cols || grid[x][y] == WALL) {
        return false;
    }

    // Implement the recursive step here.
    
    /*
    Below is the description of this function from the readme. You should think about how to implement this logic.

    This function uses recursion to find the lexicographically smallest path 
    from the START cell to the END cell, and print the path as a sequence of moves. 
    Only moves to the right (East) and down (South) are allowed. 
    Since we are travelling from the upper leftmost square to the lower rightmost 
    square and we can only move south or east, any valid path will have the 
    same number of south and east moves regardless of obstacles in the grid. Thus, 
    the lexicographical smallest path is the valid path where we always move east when 
    we can, and move south only when we have to. Thus, using recursion, you need to find 
    the path where you move east until you cannot move east anymore (because of an obstacle 
    or because you reached the boudanries of your grid), then move south just enoough until 
    you can move east again (if you can), until you reach the END square. 
    */

    /* Hint :
    You should first check if you can move east, then check if you can move south.
    If a path in invalid because of an obstacle, you should cancel this path.
    Cancelling the path is equivalent to cancelling the last move you made, 
    or cancelling the last 2 moves, or 3... etc, as many as you need. This is called backtracking.
    */
    //moving east
    if (y + 1 < cols && grid[x][y + 1] != WALL) {
        path[pos] = EAST;
        if (lexicographically_smallest_path_util(grid, rows, cols, x, y + 1, path, pos + 1)) {
            return true;
        }
    }
    //moving south
    if (x + 1 < rows && grid[x + 1][y] != WALL) {
        path[pos] = SOUTH;
        if (lexicographically_smallest_path_util(grid, rows, cols, x + 1, y, path, pos + 1)) {
            return true;
        }
    }

    // If no path is valid, return appropriate value (think about what would be 
    // useful for`lexicographically_smallest_path` to know when no path is found)
    return false;
}

void lexicographically_smallest_path(char **grid, int rows, int cols) {
    
    // Initialize an array of characters of size 100 to store the path
    char path[100];
    // Intialize a position tracker to append characters to the path correctly
    int start_x = -1, start_y = -1;
    bool end_found = false;

    // Make sure the START and the END squares are in the grid. If they are not print NA and return
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == START) {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == END) {
                end_found = true;
            }
        }
    }
    if (start_x == -1 || start_y == -1 || !end_found) {
        printf("-1\n");
        return;
    }

    // Call the utility function `lexicographically_smallest_path_util` with the correct parameters 
    // You can either look for the START square or hardcode it since we always start from the top left corner
    
    // Check if the utility function found a path, and print the path if it did
    // If no path is found, print -1
    // Reminder for printing : To use printf("%s", ...) to print an array of characters in C, 
    // you need to add a null character at the end of the array to make it a string
    if (!lexicographically_smallest_path_util(grid, rows, cols, start_x, start_y, path, 0)) {
        printf("-1\n"); // Print -1 if no valid path is found
    }
}
