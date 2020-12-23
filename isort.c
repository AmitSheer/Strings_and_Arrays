//
// Created by Amit-Sheer Cohen on 23/12/2020.
//

#include "isort.h"
#include <stdio.h>
#define MAX_INPUT_ARRAY 50
void shift_element(int* arr, int i){
    int eleToMoveLeft = *(arr+i);
    for (int j = i-1; 0<=j ; --j) {
        int temp = *(arr+j);
        *(arr+j+1) =  temp;
    }
    *(arr) = eleToMoveLeft;
}

void insertion_sort(int* arr , int len){
    //for for all elements in array
    for (int i = 0; i < len; ++i) {
        int min = *(arr+i);
        int index = 0;
        for (int j = i; j < len; ++j) {
            if(*(arr+j)<min){
                index=j-i;
                min = *(arr+j);
            }
        }
        shift_element(arr+i,index);
    }
}

int main(){
    int arr[MAX_INPUT_ARRAY] = {};
    for (int i = 0; i < MAX_INPUT_ARRAY; ++i) {
        scanf(" %d",&*(arr+i));
    }
    insertion_sort(arr, MAX_INPUT_ARRAY);
    for (int i = 0; i < MAX_INPUT_ARRAY-1; ++i) {
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+MAX_INPUT_ARRAY-1));

}