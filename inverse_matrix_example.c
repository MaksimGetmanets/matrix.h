#include "matrix.h"

int main() {
  matrix_t A = {0}, result = {0};

create_matrix(3, 3, &A);

A.matrix[0][0] = 4; A.matrix[0][1] = 7; A.matrix[0][2] = 2;
A.matrix[1][0] = 3; A.matrix[1][1] = 6; A.matrix[1][2] = 1;
A.matrix[2][0] = 2; A.matrix[2][1] = 5; A.matrix[2][2] = 9;

int status = inverse_matrix(&A, &result);
if (status == 0) {
    printf("inverse matrix found\n");
}

remove_matrix(&A);
remove_matrix(&result);
}
