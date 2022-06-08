#include "matrix.h"

int m_get(int x, int y, int newX, int newY, MATRIX macierz) {
    int temp = y * (newX - 1) + newY - 1;
    return macierz.wsk[temp];
}