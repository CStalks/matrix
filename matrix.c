#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 5
#define N 6

void matrixArrayOfArrays(int m, int n);
void matrixOneBigArray(int m, int n);

int main(int argc,char** argv){
    matrixArrayOfArrays(M,N);
    matrixOneBigArray(M,N);
    return 0;
}

void matrixArrayOfArrays(int m, int n){
    float **arr = NULL;
    arr = (float **)malloc(m*sizeof(float *));

    //make each pointer to float element points to n bytes(rows) of memory 
    for(int i = 0; i < m; i++){
        arr[i] = (float *)malloc(n*sizeof(float)); 
    }

    //assign values to the array
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
             arr[i][j] = i * N + j + 1; 
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    //free the memory that was allocated and assigned for each of the float pointers
    for(int i = 0; i < m; i++){
        free(arr[i]); 
    }
    //free the memory that was allocated for each of the float pointers
    free(arr);
}

void matrixOneBigArray(int m, int n){
    float **arr = (float **)malloc(m*sizeof(float*));
    float *arr = (float *)malloc(m*n*sizeof(float));

    for(int i = 1; i < M; i++){
        arr[i] = arr[0] + n * i;
    }
}