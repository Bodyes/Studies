#ifndef ZAD15_MATRIX_H
#define ZAD15_MATRIX_H

typedef struct MATRIX_S {
    int x;
    int y;
    int * wsk;
}MATRIX;

MATRIX m_create(int, int);
int m_remove(MATRIX *);

int m_scanf(MATRIX *, int, int);
int m_scanf_(MATRIX *, int, int);
int m_printf(MATRIX);

int m_get(int, int, int, int, MATRIX);
int m_put(int, int, int, int, int, MATRIX);

int m_determinant(int n,  int x, int matrix[n][n]);
void m_subMatrix(int x, int matrix[x][x], int temp[x][x], int p, int q, int n);
int m_detOfMatrix(MATRIX *macierz);

MATRIX m_multiplication(MATRIX *macierz, MATRIX *macierz2);

#endif