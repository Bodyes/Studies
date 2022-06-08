#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortint.h"

void bubbleSort(int *array, int arraySize, int elementSize, int comp_int(const void *, const void *)){
    for(int i = 0; i<arraySize-1; i++){ //ostatniego elementu nie trzeba sortowac
        for(int j = 0; j<arraySize-i-1; j++){
            if(comp_int(array+j, array+j+1)>0){
                swap(array+j, array+j+1, elementSize);
            }
        }
    }
}

void selectSort(int *array, int arraySize, int elementSize, int comp_int(const void *, const void *)){
    int min;

    for(int i = 0; i<arraySize-1; i++){
        min = i;

        for(int j = i+1; j < arraySize; j++){
            if(comp_int(array+j, array+min)<0) min = j;
        }
        swap(array+min, array+i, elementSize);
    }
}

int comp_int(const void * ad1, const void * ad2){
    return *(const int *) ad1 - *(const int *) ad2;
}

void swap(void *ad1, void *ad2, int bytes){
    char *temp = malloc(bytes);
    memcpy(temp, ad1, bytes);
    memcpy(ad1, ad2, bytes);
    memcpy(ad2, temp, bytes);
    free(temp);
    temp = NULL;
}

int main(int argc, char **argv) {

    int sort, exit = 1;

    if (argc > 3 || argc == 1) {
        printf("\nusage:\t ./zad18b -nvalue \n\nPossible values:\nbubble - for bubble sort\nselect - for select sort\nq for qsort");
        return 1;
    }

    if(argc == 2){
        if(!strcmp(argv[1], "-nbubble")){
            sort = 1;
            exit = 0;
        }
        else if(!strcmp(argv[1], "-nselect")){
            sort = 2;
            exit = 0;
        }
        else if(!strcmp(argv[1], "-nq")) {
            sort = 3;
            exit = 0;
        }
    }
    else{
        if(!strcmp(argv[1], "-n")){
            if(!strcmp(argv[2], "bubble")){
                sort = 1;
                exit = 0;
            }
            else if(!strcmp(argv[2], "select")){
                sort = 2;
                exit = 0;
            }
            else if(!strcmp(argv[2], "q")){
                sort = 3;
                exit = 0;
            }
        }
        else exit = 1;
    }

    if(exit) {
        printf("\nusage:\t ./zad18b -nvalue \n\nPossible values:\nbubble - for bubble sort\nselect - for select sort\nq for qsort");
        return 1;
    }

    int arraySize;
    printf("Enter array size greater than 1:\n");
    do{
        scanf("%d", &arraySize);
        if(arraySize<=1) printf("Try again. \n");
    }while(arraySize<=1);

    printf("\n");

    int *array = calloc(arraySize,sizeof(int));

    if(array == NULL) realloc(array, sizeof(int)*arraySize);


    printf("Enter array values after enter each: \n");

    for(int i=0; i<arraySize; i++){
        scanf("%d", &array[i]);
    }

    for(int i=0; i<arraySize; i++){
        printf("%d ", array[i]);
    }

    if(sort == 1) bubbleSort(array, arraySize, sizeof(int), comp_int);
    else if(sort == 2) selectSort(array, arraySize, sizeof(int), comp_int);
    else qsort(array, arraySize, sizeof(int), comp_int);

    printf("\n");

    for(int i=0; i<arraySize; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    free(array);
    array = NULL;

    return 0;
}
