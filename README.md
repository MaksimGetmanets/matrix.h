# matrix.h
custom library for operations with matrix

matrix — это библиотека на языке C для работы с матрицами, реализующая основные операции линейной алгебры. Проект представляет собой аналог стандартной библиотеки работы с матрицами.

Библиотека поддерживает операции сложения, вычитания, умножения на число, умножения матриц, транспонирования, вычисления определителя, нахождения обратной матрицы и матрицы алгебраических дополнений.


Функция	Описание	Код возврата
create_matrix	Создание матрицы	0 - OK, 1 - ошибка
remove_matrix	Очистка памяти	void
eq_matrix	Сравнение матриц	1 - равны, 0 - не равны
sum_matrix	Сложение матриц	0 - OK, 1 - ошибка, 2 - ошибка вычислений
sub_matrix	Вычитание матриц	0 - OK, 1 - ошибка, 2 - ошибка вычислений
mult_number	Умножение на число	0 - OK, 1 - ошибка, 2 - ошибка вычислений
mult_matrix	Умножение матриц	0 - OK, 1 - ошибка, 2 - ошибка вычислений
transpose	Транспонирование	0 - OK, 1 - ошибка
calc_complements	Матрица дополнений	0 - OK, 1 - ошибка, 2 - ошибка вычислений
determinant	Определитель матрицы	0 - OK, 1 - ошибка, 2 - ошибка вычислений
inverse_matrix	Обратная матрица	0 - OK, 1 - ошибка, 2 - ошибка вычислений

Сборка библиотеки выполняется командой make all

Коды возврата

Константа	Значение	Описание
OK	0	Успешное выполнение
INCORRECT_MATRIX	1	Некорректная матрица (NULL, нулевой размер, и т.д.)
CALC_ERROR	2	Ошибка вычислений (переполнение, нулевой определитель, и т.д.)
SUCCESS	1	Матрицы равны
FAILURE	0	Матрицы не равны

============================================================================================

Matrix is ​​a C library for working with matrices, implementing the basic operations of linear algebra. The project is analogous to a library for working with matrices.

The library supports operations such as addition, subtraction, multiplication of numbers, matrix multiplication, transposition, determinant calculation, inverse matrix calculation, and matrix cofactors.

function Description Return code create_matrix Create matrix 0 - OK, 1 - error remove_matrix Clear memory void eq_matrix Compare matrix 1 -, 0 - not sum_matrix Add matrix 0 - OK, 1 - error, 2 - formula error sub_matrix Subtract matrix 0 - OK, 1 - error, 2 - calculation error mult_number Multiply by number 0 - OK, 1 - error, 2 - calculation error mult_matrix Multiply matrices 0 - OK, 1 - error, 2 - calculation error transpose Transpose 0 - OK, 1 - error calc_complements Complements matrix 0 - OK, 1 - error, 2 - comp error determinant Matrix determinant 0 - OK, 1 - error, 2 - calculation error inverse_matrix Inverse matrix 0 - OK, 1 - error, 2 - calculation error

Command to assembly: make all

Return codes

Constant Description OK 0 Successful execution INCORRECT_MATRIX 1 Uncorrected matrix (NULL, zero size, etc.) CALC_ERROR 2 Calculation error (overflow, zero determinant, etc.) SUCCESS 1 Matrix FAILURE 0 No matrices required
