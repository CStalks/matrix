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


}

void matrixOneBigArray(int m, int n){

}

