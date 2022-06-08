#include "matrix.h"

MATRIX m_multiplication(MATRIX *macierz, MATRIX *macierz2){
    int newTab[macierz->x][macierz2->y], macierzTab[macierz->x][macierz->y], macierz2Tab[macierz2->x][macierz2->y];
    int temp=0;
    MATRIX *newMatrix;
    *newMatrix = m_create(macierz->x, macierz2->y);

    for(int i=0; i<macierz->x; i++){
        for(int j=0; j<macierz->y; j++){
            macierzTab[i][j] = macierz->wsk[temp];
            temp++;
        }
    }
    temp=0;
    for(int i=0; i<macierz2->x; i++){
        for(int j=0; j<macierz2->y; j++){
            macierz2Tab[i][j] = macierz2->wsk[temp];
            temp++;
        }
    }

    for (int i = 0; i < macierz->x; i++) {
        for (int j = 0; j < macierz2->y; j++) {
            newTab[i][j] = 0;

            for (int k = 0; k < macierz2->x; k++) {
                newTab[i][j] += macierzTab[i][k] * macierz2Tab[k][j];
            }
        }
    }

    temp=0;
    for(int i=0; i<macierz->x; i++){
        for(int j=0; j<macierz2->y; j++) {
            newMatrix->wsk[temp] = newTab[i][j];
            temp++;
        }
    }

    return *newMatrix;

}