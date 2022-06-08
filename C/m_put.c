#include "matrix.h"
int m_put(int x, int y, int newX, int newY, int value, MATRIX macierz) {
    int temp = y * (newX - 1) + newY - 1;

    macierz.wsk[temp] = value;
    return 1;
}
