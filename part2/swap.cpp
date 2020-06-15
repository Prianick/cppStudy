
void swap_min1(int *m[], unsigned rows, unsigned cols) {
    int min = m[0][0];
    int rowId = 0;
    int *firstRow = m[0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (m[i][j] < min) {
                min = m[i][j];
                rowId = i;
            }
        }
    }
    int *needRow = m[rowId];
    m[0] = needRow;
    m[rowId] = firstRow;
}


int main() {
    unsigned rows = 4;
    unsigned cols = 3;

    /**
     * Здесь мы создаем двумерный массив на основе одномерного.
     * Как?
     * Создаем массив указателей на каждую строку.
     * Создаем массив с площадью равной площади матрицы.
     * Дальше берем место куда указывает указатель m[0],
     * а он указывает на начало выделенного массивае, прибавляем к нему 3 ячейки
     * таким образам выделяем память под три колонки. После этого у нас в руках
     * оказывается ячейка на нужном расстоянии от предыдушей,
     * её адрес мы присываиваем второму(m[1]) указателю и тд.
     */
    int **m = new int *[rows];
    m[0] = new int[rows * cols];
    for (unsigned i = 1; i < rows; ++i) {
        m[i] = m[i - 1] + cols;
    }

    int m2[4][3] = {
            {21, 2, 23},
            {3,  4, 6},
            {1,  2, 4},
            {2,  5, 8},
    };

    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i) {
            m[j][i] = m2[j][i];
        }
    }

    swap_min1(m, rows, cols);
}