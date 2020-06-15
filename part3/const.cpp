#include <iostream>


/**
 * Lesson 3.6
 * @return
 */
int main() {
    int const days[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

//    const unsigned int DIM1 = 3;
//    const unsigned int DIM2 = 5;

    int const ary[3][5] = {
            { 1, 2, 3, 4, 5 },
            { 2, 4, 6, 8, 10 },
            { 3, 6, 9, 12, 15 }
    };

    int const * const *m1 = new int const *[2];

    // Получаем адрес ячейки (&) приводим его к указателю (int *),
    // потом можно попытаться изменить значение ячейки под жтим указателем *m2 = 30;
    int * m2 = (int *)&ary[1][1];


//    int const * const * const m;

    unsigned rows = 10;
    unsigned cols = 3;

    int **m3 = new int *[rows];
    m3[0] = new int[rows * cols];
    for (unsigned i = 1; i < rows; ++i) {
        m3[i] = m3[i - 1] + cols;
    }

    bool const stop = true;
}