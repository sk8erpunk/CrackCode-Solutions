/******************************************************************************
Zero matrix
Write an algorithm such that if an element is an MxN matrix is 0, its entire row
and column are set to 0.
*******************************************************************************/
#include <stdio.h>
#include <iostream>

#define N 5
#define M 4

using namespace std;

void zeroRow(int matrix[][M], int r){
    for(int j = 0; j < M; j++){
        matrix[r][j] = 0;
    }
}

void zeroCol(int matrix[][M], int c){
    for(int i = 0; i < N; i++){
        matrix[i][c] = 0;
    }
}

// Time complexity is O(MN)
// Memory space is O(N+M)
void zeroMatrix(int matrix[][M]){
    int rows[N] = {0};
    int cols[M] = {0};
    
    // find which rows and cols has zero in thier cell
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }        
        }
    }
    // zeroing rows
    for(int i = 0; i < N; i++){
        if(rows[i])
            zeroRow(matrix,i);
    }
    // zeroing cols 
    for(int j = 0; j < M; j++){
        if(cols[j])
            zeroCol(matrix,j);
    }
}

int main()
{
    int arr[N][M] =
    {
        {1,3,4,5},
        {6,0,9,1},
        {3,4,5,5},
        {6,0,9,0},
        {1,3,4,5}
    };
    zeroMatrix(arr);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}