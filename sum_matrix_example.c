#include "matrix.h"

int main() {
    matrix_t A = {0}, B = {0}, result = {0};
    create_matrix(2, 2, &A);
    create_matrix(2, 2, &B);
    
    A.matrix[0][0] = 1; A.matrix[0][1] = 2;
    A.matrix[1][0] = 3; A.matrix[1][1] = 4;
    
    B.matrix[0][0] = 5; B.matrix[0][1] = 6;
    B.matrix[1][0] = 7; B.matrix[1][1] = 8;
    
    int status = sum_matrix(&A, &B, &result);
    if (status == 0) {
        printf("addition completed successfully\n");
    }
    
    remove_matrix(&A);
    remove_matrix(&B);
    remove_matrix(&result);
    return 0;
}
