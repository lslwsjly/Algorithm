//
//  prob2-1.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/29.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;

int k;
const int maxValue = 2000000;
int vector[maxValue];
// merge array[start...middle], array[middle+1...end]
void merge(int array[], int start, int middle, int end) {
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
                //we do not need to copy since the right part of the array has been sorted
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
void insertSort(int array[], int start, int end) {
    for (int j = start + 1; j <= end; j++) {
        int key = array[j];
        int i = j - 1;
        while(i >=start && array[i] > key) {
            array[i+1] = array[i];
            i --;
        }
        array[i+1] = key;
    }
}
void mergeSort(int array[], int start, int end) {
    if (end - start <= k+1) {
        insertSort(array, start, end);
        return;
    }
    int middle = (start + end)/2;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    clock_t start, end;
    
    int a[maxValue];
    k = 2;
    while (k < 100) {
        for (int i = 0; i < maxValue; i++) {
            a[i] = maxValue-i;
        }
        start = clock();
        mergeSort(a, 0, maxValue-1);
        end = clock();
        cout << "time for "<< k <<": " << (end - start)*1000/CLOCKS_PER_SEC << endl;
        k*=2;
    }
    return 0;
}