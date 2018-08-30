#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack/stack.h"

#define MARKED 1

static int row_neighbors[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int col_neighbors[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int **marked;

int valid_address(int i, int j, int m, int n) {
    if (i >= 0 && i < m) {
        if (j >= 0 && j < n) {
            return 1;
        }
    }
    return 0;
}

void dfs(int input[][5], int i, int j) {
    // Mark input
    marked[i][j] = MARKED;
    // For each neighbor
    for (int index = 0; index < 8; index++) {
        int neighbor_row = i + row_neighbors[index];    // Get neighbor row
        int neighbor_col = j + col_neighbors[index];    // Get neighbor col
        // Check if address is okay, and check if neighbor is not marked already
        if (valid_address(neighbor_row, neighbor_col, 5, 5) && !marked[neighbor_row][neighbor_col]) {
            int neighbor = input[neighbor_row][neighbor_col];
            // If neighbor is a one, run dfs on it
            if (neighbor == 1) {
                dfs(input, neighbor_row, neighbor_col);
            }
        }

    }
}

int count_islands(int input[][5], unsigned int m, unsigned int n) {
    int count = 0;

    marked = (int **) calloc(m, sizeof(int*));
    for (unsigned int i = 0; i < m; i++) {
        marked[i] = calloc(n, sizeof(int));
    }

    for (unsigned int i = 0; i < m; i++ ) {
        for (unsigned int j = 0; j < n; j++) {
            if (input[i][j] == 1 && !marked[i][j]) {
                dfs(input, i, j);
                count++;
            }
        }
    }
    return count;
}

int is_permutation(const char *a, const char *b) {
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);
    int alphabet[256] = {0};

    if (a_len != b_len) {
        return 0;
    }

    for (unsigned int i = 0; i < a_len; i++) {
        alphabet[(unsigned int) a[i]]++;
    }

    for (unsigned int i = 0; i < b_len; i++) {
        alphabet[(unsigned int) b[i]]--;
        if (alphabet[(unsigned int) b[i]] < 0) {
            return 0;
        }
    }
    return 1;
}


int unique_chars(const char *string) {
    int alphabet[256] = {0};
    int current_index = 0;

    char current_value = string[current_index];
    while (current_value != '\0') {
        if (alphabet[(int) current_value] == 0) {
            alphabet[(int) current_value] = 1;
            current_index++;
            current_value = string[current_index];
        } else {
            return 0;
        }
    }
    return 1;
}

void reverse_string(char *string) {
    int n = 0;
    while (string[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n / 2; i++) {
        char temp = string[i];
        string[i] = string[n - i - 1];
        string[n - i - 1] = temp;
    }
}

int main() {
    stack_arr_t *s = NULL;
    int result = stack_arr_init(&s, 10, sizeof(unsigned char));
    printf("stack init result = %d\n", result);
    char temp = 'a';
    stack_arr_push(s, (void *) &temp);
    printf("stack size now = %d, temp = %d\n", s->size, temp);
    stack_arr_pop(s, (void *) &temp);
    printf("stack size now = %d, temp = %d\n", s->size, (int) temp);
    stack_arr_free(&s);
    printf("s = %p\n", s);
    return 0;
}