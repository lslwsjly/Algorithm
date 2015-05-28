//
//  mergeSort.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/28.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace::std;

int *vector;

template <class T>
// merge array[start...middle], array[middle+1...end]
void merge(T array[], int start, int middle, int end) {
    if (start == end) {
        return;
    }
    int s1 = start;
    int s2 = middle + 1;
    for(int i = start; i <= end; i++) {
        vector[i] = array[i];
    }
    int pos = start;
    while (pos <= end) {
        if (s1 > middle || s2 > end) {
            if (s2 > end) {
                while (pos <= end) {
                    array[pos++] = vector[s1++];
                }
            } else {
                pos = end + 1;
            }
        } else {
            if (vector[s1] < vector[s2]) {
                array[pos++] = vector[s1++];
            } else {
                array[pos++] = vector[s2++];
            }
        }
    }
}
template <class T>
void mergeSort(T array[], int start, int end) {
    if (start == end) {
        return;
    }
    int middle = (start + end)/2;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
    
}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    int a[7] = {9,1,3,10,2,6,7};
//    vector = new int[7];
//    mergeSort(a, 0, 6);
//    for (int i = 0; i < 7; i++) {
//        cout << a[i] << " ";
//    }
//    return 0;
//}