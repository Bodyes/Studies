#include "matrix.h"
#include <stdlib.h>
int m_scanf_(MATRIX * macierz, int x, int y){

    if (macierz == NULL) *macierz = m_create(x, y);

    int arrayLength = sizeof(&macierz->wsk) / sizeof(&macierz->wsk[0]);

    if (arrayLength != x * y)
        macierz->wsk = realloc(macierz->wsk, sizeof(int) * x * y);

    m_scanf(macierz, x, y);
    return 1;
}