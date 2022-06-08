#include "matrix.h"
#include <stdio.h>

int m_printf(MATRIX macierz) {
    int temp = macierz.x * macierz.y;

    if (macierz.wsk == NULL) return 0;

    for (int i = 1; i <= temp; i++) {
        printf("%d ", macierz.wsk[i - 1]);
        if (i % macierz.y == 0) printf("\n");
        if (macierz.wsk[i - 1] <= 0) return 0;
    }

    return 1;
}