#include "matrix.h"
#include <stdlib.h>
MATRIX m_create(int rows, int columns){
    MATRIX macierz;
    macierz.x = rows;
    macierz.y = columns;
    macierz.wsk = (int *)calloc(rows*columns, sizeof(int));
    if(macierz.wsk == NULL){
        macierz.x = 0;
        macierz.y = 0;
    }
    return macierz;
}