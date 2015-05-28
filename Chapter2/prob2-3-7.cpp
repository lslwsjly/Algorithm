//
//  prob2.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/28.
//  Copyright (c) 2015年 lsl. All rights reserved.
//
#include <iostream>
using namespace std;
void merge(int array[], int start, int middle, int end, int vector[]) {
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
void mergeSort2(int array[], int start, int end, int vector[]) {
    if (start == end) {
        return;
    }
    int middle = (start + end)/2;
    mergeSort2(array, start, middle, vector);
    mergeSort2(array, middle + 1, end, vector);
    merge(array, start, middle, end, vector);
    
}

bool check(int a[], int length, int x) {
    int left = 0;
    int right = length - 1;
    while (left != right) {
        if (a[left] + a[right] == x) {
            return true;
        }
        if (a[left] + a[right] < x) {
            left ++;
        } else {
            right --;
        }
    }
    return false;
}

int main() {
    int a[6] = {1,3,4,9,6,3};
    int *vector = new int[6];
    mergeSort2(a, 0, 5, vector);
    cout << check(a, 6, 5) << endl;
    cout << check(a, 6, 8) << endl;
    return 0;
}