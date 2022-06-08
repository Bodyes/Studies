#include "matrix.h"
#include <stdio.h>

int m_scanf(MATRIX * macierz, int x, int y) {
    int temp = macierz->y * (x - 1) + y - 1;

    for (int i = 0; i <= temp; i++) {
        printf("Wprowadz wartosc, ktora chcesz dodac: ");
        scanf("%d", &macierz->wsk[i]);
    }
    return 1;
}
