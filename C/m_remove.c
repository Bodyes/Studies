#include "matrix.h"
#include <stdlib.h>

int m_remove(MATRIX * macierz) {
    if (macierz == NULL) {
        return 1;
    }
    free(macierz->wsk);
    macierz->wsk = NULL;
    macierz->x = 0;
    macierz->y = 0;
    return 0;
}
