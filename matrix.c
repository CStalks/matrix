#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 4
#define COL 4

void createArrayOfArrays(int row, int col);
void flattenMatrix(int row, int col);

int main(int argc,char** argv){
    createArrayOfArrays(ROW,COL);
    flattenMatrix(ROW,COL);
    return 0;
}

void createArrayOfArrays(int row, int col){
    float **arr = NULL;
    //allocate the memory for the array float pointers(float *)
    arr = (float **)malloc(row*sizeof(float *));

    //make each pointer to float element points to n bytes(rows) of memory 
    for(int i = 0; i < row; i++){
        arr[i] = (float *)malloc(col*sizeof(float)); 
    }

    //assign values to the array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
             arr[i][j] = i * col + j + 1; 
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

     for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%f\t", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    //free the memory that was allocated and assigned for each of the float pointers
    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    //free the memory that was allocated for each of the float pointers
    free(arr);
}

void flattenMatrix(int row, int col){
    //allocate memory for the one large block of array
    float **arr = (float **)malloc(row*sizeof(float*));
    *arr = (float *)malloc(col*row*sizeof(float));

    //make each float pointer(float *) points to n positions  
    for(int i = 1; i < row; i++){
        arr[i] = arr[0] + col * i;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = i * col + j + 1;                                             
        }                                                  
    }

     for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%f\t", arr[i][j]);                                                                                          
        }
        printf("\n");
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
     printf("\n");

     for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%f\t", arr[j][i]);
        }
        printf("\n");
    }

    free(arr[0]);
    free(arr);
}
