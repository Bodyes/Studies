#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortstr.h"

void bubbleSort(char *array[], int arraySize, int elementSize, int comp_str(const void *, const void *)){
    for(int i = 0; i<arraySize-1; i++){
        for(int j = 0; j<arraySize-i-1; j++){
            if(comp_str(array+j,array+j+1)>0){
                swap(array+j, array+j+1, elementSize);
            }
        }
    }
}

void selectSort(char *array[], int arraySize, int elementSize, int comp_str(const void *, const void *)){
    int min;

    for(int i = 0; i<arraySize-1; i++){
        min = i;

        for(int j = i+1; j < arraySize; j++){
            if(comp_str(array+j,array+min)<0) min = j;
        }
        swap(array+min, array+i, elementSize);
    }
}

int comp_str(const void * ad1, const void * ad2){
    return strcmp(*(const char **) ad1, *(const char **) ad2);
}

void swap(void *ad1, void *ad2, int bytes){
    char *temp = malloc(bytes);
    memcpy(temp, ad1, bytes);
    memcpy(ad1, ad2, bytes);
    memcpy(ad2, temp, bytes);
    free(temp);
    temp = NULL;
}

int main(int argc, char *argv[]) {
    int sort, exit = 1, arraySize;
    char **stringList;
    char *string;
    if (argc > 3 || argc == 1) {
        printf("\nusage:\t ./zad18 -nvalue \n\nPossible values:\nbubble - for bubble sort\nselect - for select sort\nq for qsort");
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
        printf("\nusage:\t ./zad18 -nvalue \n\nPossible values:\nbubble - for bubble sort\nselect - for select sort\nq for qsort");
        return 1;
    }

    printf("Enter array size greater than 1:\n");
    do{
        scanf("%d", &arraySize);
        if(arraySize<=1) printf("Try again. \n");
    }while(arraySize<=1);

    stringList = (char**)calloc(arraySize, sizeof(char**));

    printf("Enter words after enter each: \n");
    for(int i=0; i<=arraySize; i++){
        string = calloc(20,sizeof(char));
        gets(string);
        if(i!=0) stringList[i - 1] = string;
    }

    for(int i=0; i<arraySize; i++){
        puts(stringList[i]);
    }

    if(sort==1) bubbleSort(stringList, arraySize, sizeof(char*), comp_str);
    else if(sort==2) selectSort(stringList, arraySize, sizeof(char*), comp_str);
    else qsort(stringList, arraySize, sizeof(char*), comp_str);
    printf("\n");

    for(int i=0; i<arraySize; i++){
        puts(stringList[i]);
    }

    free(string);
    string = NULL;
    free(stringList);
    stringList = NULL;

    return 0;
}
