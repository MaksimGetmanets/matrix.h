#include "matrix.h"

int main() {
    matrix_t A = {0};
    
    // Create matrix 3x3
    create_matrix(3, 3, &A);
    
    // filling with values
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            A.matrix[i][j] = i * A.columns + j + 1;
        }
    }
    
    // memory free
    remove_matrix(&A);
    
    return 0;
}
