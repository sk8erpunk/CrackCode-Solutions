/******************************************************************************
Rotate Matrix 
Given an image represtented by an NxN matrix, where each pixel in the image is 
4 bytes, write a method to rotate the image by 90 degress. Can you do this in 
place? 
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#define N 5

using namespace std;

void rotateMatrix(int matrix[][N]){
    for(int layer = 0; layer < N/2; layer++){   // divide to layers 
        for(int i = layer; i < N-layer-1; i++){ // rotate each layer 
            int temp = matrix[i][N-layer-1];    // save right
            matrix[i][N-layer-1] = matrix[layer][i];    // move top to right
            matrix[layer][i] = matrix[N-i-1][layer];    // move left to top
            matrix[N-i-1][layer] = matrix[N-layer-1][N-i-1];    // move bottom to left
            matrix[N-layer-1][N-i-1] = temp;    // move right to bottom
        }
    }
}


int main()
{
    int arr[N][N] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    rotateMatrix(arr);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
