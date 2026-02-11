#include "matrix.h"

static int check_two_matrix(matrix_t* A, matrix_t* B) {
  if (A == NULL || B == NULL) return INCORRECT_MATRIX;

  if (A->matrix == NULL || B->matrix == NULL) return INCORRECT_MATRIX;
  if (A->columns <= 0 || A->rows <= 0) return INCORRECT_MATRIX;
  if (B->columns <= 0 || B->rows <= 0) return INCORRECT_MATRIX;

  if (A->rows != B->rows || A->columns != B->columns) return CALC_ERROR;

  return OK;
}

static int minor_matrix(matrix_t* A, int skip_rows, int skip_columns,
                        matrix_t* result) {
  if (skip_rows < 0 || skip_rows >= A->rows || skip_columns < 0 ||
      skip_columns >= A->columns)
    return CALC_ERROR;
  if (A->rows < 2 || A->columns < 2) return CALC_ERROR;

  int create_status = create_matrix(A->rows - 1, A->columns - 1, result);
  if (create_status != OK) return create_status;

  int minor_col = 0;
  int minor_row = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i == skip_rows) continue;
    minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == skip_columns) continue;

      result->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
  return OK;
}

int create_matrix(int rows, int columns, matrix_t* result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  }

  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;

  result->matrix = malloc(rows * sizeof(double*));
  if (result->matrix == NULL) {
    result->rows = 0;
    result->columns = 0;
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = malloc(columns * sizeof(double));

    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(result->matrix[j]);
      }
      free(result->matrix);
      result->matrix = NULL;
      result->rows = 0;
      result->columns = 0;
      return INCORRECT_MATRIX;
    }

    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }

  return OK;
}

void remove_matrix(matrix_t* A) {
  if (A != NULL) {
    if (A->matrix != NULL && A->rows > 0) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] != NULL) {
          free(A->matrix[i]);
        }
      }
      free(A->matrix);
    }
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int eq_matrix(matrix_t* A, matrix_t* B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL)
    return FAILURE;

  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > eps) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}

int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;

  int check_result = check_two_matrix(A, B);
  if (check_result != OK) return check_result;

  int create_result = create_matrix(A->rows, A->columns, result);
  if (create_result != OK) return create_result;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;

  int check_result = check_two_matrix(A, B);
  if (check_result != OK) return check_result;

  int create_result = create_matrix(A->rows, A->columns, result);
  if (create_result != OK) return create_result;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int mult_number(matrix_t* A, double number, matrix_t* result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;

  int create_result = create_matrix(A->rows, A->columns, result);
  if (create_result != OK) return create_result;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;
  if (B->rows <= 0 || B->columns <= 0 || B->matrix == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;

  int create_result = create_matrix(A->rows, B->columns, result);
  if (create_result != OK) return create_result;

  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; ++k) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int transpose(matrix_t* A, matrix_t* result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;

  int create_flag = create_matrix(A->columns, A->rows, result);
  if (create_flag != OK) return create_flag;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}

int calc_complements(matrix_t* A, matrix_t* result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;

  int create_flag = create_matrix(A->rows, A->columns, result);
  if (create_flag != OK) return create_flag;

  if (A->rows == 1) {
    result->matrix[0][0] = 1.0;
    return OK;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor = {0};
      int flag = minor_matrix(A, i, j, &minor);
      if (flag != OK) {
        remove_matrix(result);
        return flag;
      }

      double minor_det;
      flag = determinant(&minor, &minor_det);
      remove_matrix(&minor);
      if (flag != OK) {
        remove_matrix(result);
        return flag;
      }

      double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
      result->matrix[i][j] = sign * minor_det;
    }
  }

  return OK;
}

int determinant(matrix_t* A, double* result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }

  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK;
  }

  *result = 0.0;
  for (int j = 0; j < A->columns; j++) {
    matrix_t minor = {0};
    int flag = minor_matrix(A, 0, j, &minor);
    if (flag != OK) return flag;

    double minor_det;
    flag = determinant(&minor, &minor_det);
    remove_matrix(&minor);
    if (flag != OK) {
      return flag;
    }

    double sign = (j % 2 == 0) ? 1.0 : -1.0;
    *result += A->matrix[0][j] * sign * minor_det;
  }

  return OK;
}

int inverse_matrix(matrix_t* A, matrix_t* result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;

  int flag = create_matrix(A->rows, A->columns, result);
  if (flag != OK) return flag;

  if (A->rows == 1) {
    if (fabs(A->matrix[0][0]) < eps) {
      remove_matrix(result);
      return CALC_ERROR;
    }
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
    return OK;
  }

  double det = 0.0;
  flag = determinant(A, &det);
  if (flag != OK) {
    remove_matrix(result);
    return flag;
  }

  if (fabs(det) < eps) {
    remove_matrix(result);
    return CALC_ERROR;
  }

  matrix_t confactor_matrix = {0};
  matrix_t transpose_confactor_matrix = {0};

  flag = calc_complements(A, &confactor_matrix);
  if (flag != OK) {
    remove_matrix(result);
    return flag;
  }

  flag = transpose(&confactor_matrix, &transpose_confactor_matrix);
  if (flag != OK) {
    remove_matrix(&confactor_matrix);
    remove_matrix(result);
    return flag;
  }

  flag = mult_number(&transpose_confactor_matrix, 1.0 / det, result);

  remove_matrix(&confactor_matrix);
  remove_matrix(&transpose_confactor_matrix);

  return flag;
}