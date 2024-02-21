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
    //allocate the memory for the array float pointers(float *)
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
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%f\t", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    //free the memory that was allocated and assigned for each of the float pointers
    for(int i = 0; i < m; i++){
        free(arr[i]);
    }
    //free the memory that was allocated for each of the float pointers
    free(arr);
}

void matrixOneBigArray(int m, int n){
    //allocate memory for the one large block of array
    float **arr = (float **)malloc(m*sizeof(float*));
    *arr = (float *)malloc(n*m*sizeof(float));

    //make each float pointer(float *) points to n positions  
    for(int i = 1; i < m; i++){
        arr[i] = arr[0] + n * i;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = i * N + j + 1; 
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
     printf("\n");

     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%f\t", arr[j][i]);
        }
        printf("\n");
    }

    free(arr[0]);
    free(arr);
}
