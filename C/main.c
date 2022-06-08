#include <stdio.h>
#include "matrix.h"

int main(){
    int rows, columns, positionRow, positionColumn, value, switchingValue, areYouSure, det;
    MATRIX macierz, macierz2, *newMatrix = NULL;

    printf("Insert matrix size (in format: rows columns)\n");
    scanf("%d %d", &rows, &columns);
    macierz = m_create(rows, columns);

    do{
        printf("\nWhat do you want to do?\n\n1. Multiply matrix\n2. Change matrix\n3. Add values(I)\n"
               "4. Add values(II)\n5. Check values\n6. Change single value\n"
               "7. Read single value\n8. Delete matrix\n9. Determinant\n0. exit.\n");

        scanf("%d", &switchingValue);

        switch(switchingValue){
            case 1:
                printf("Podaj ilosc wierszy i kolumn drugiej macierzy (wiersze kolumny)\n");
                scanf("%d %d", &rows, &columns);
                macierz2 = m_create(rows, columns);
                m_scanf_(&macierz2, rows, columns);

                *newMatrix = m_multiplication(&macierz, &macierz2);
                m_printf(*newMatrix);
                break;
            case 2:
                printf("Podaj ilosc wierszy i kolumn macierzy (wiersze kolumny)\n");
                scanf("%d %d", &rows, &columns);
                m_remove(&macierz);
                macierz = m_create(rows, columns);
                break;
            case 3:
                m_scanf(&macierz, rows, columns);
                break;
            case 4:
                m_scanf_(&macierz, rows, columns);
                break;
            case 5:
                m_printf(macierz);
                break;
            case 6:
                printf("Ktora pozycje chcesz dodac, jaka wartosc? Podaj w formacie (wiersz kolumna wartosc)\n");
                scanf("%d %d %d", &positionRow, &positionColumn, &value);
                m_put(rows, columns, positionRow, positionColumn, value, macierz);
                break;
            case 7:
                printf("Ktora pozycje chcesz zobaczyc? Podaj w formacie (wiersz kolumna)\n");
                scanf("%d %d", &positionRow, &positionColumn);
                printf("Liczba na tym miejsu, to: %d", m_get(rows, columns, positionRow, positionColumn, macierz));
                break;
            case 8:
                printf("Czy jestes tego pewien? Wpisz \"7352\" jesli tak.\n");
                scanf("%d", &areYouSure);
                if(areYouSure == 7352){
                    m_remove(&macierz);
                }
                break;
            case 9:
                det = m_detOfMatrix(&macierz);
                printf("Wyznacznik jest równy: %d\n",det);
                break;
        }

    } while (switchingValue!=0);


    if(macierz.wsk != NULL) m_remove(&macierz);
    if(macierz2.wsk != NULL) m_remove(&macierz2);
    if(newMatrix->wsk != NULL) m_remove(newMatrix);


    return 0;
}