#include <stdio.h>
#include "matrix.h"

int m_detOfMatrix(MATRIX *macierz){
    if(macierz->x != macierz->y){
        printf("Macierz nie jest kwadratowa.");
        return 0;
    }

    int x=macierz->x, temp2=0;
    int matrix[x][x];

    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            matrix[i][j] = macierz->wsk[temp2];
            temp2++;
        }
    }

    return m_determinant(x, x, matrix);
}

int m_determinant(int n, int x, int matrix[x][x]) {
    int det = 0;

    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    int temp[x][x], sign = 1;
    for (int i = 0; i < n; i++) {
        m_subMatrix(x, matrix, temp, 0, i, n);
        det += sign * matrix[0][i] * m_determinant(n-1, x, temp);
        sign = -sign;
    }
    return det;
}

void m_subMatrix(int x, int mat[x][x], int temp[x][x], int p, int q, int n) {
    int i = 0, j = 0;
    // filling the sub matrix
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            // skipping if the current row or column is not equal to the current
            // element row and column
            if (row != p && column != q) {
                temp[i][j++] = mat[row][column];
                if (j == n-1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

