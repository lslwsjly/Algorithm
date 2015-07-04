//
//  prob2-4.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/29.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXSIZE = 100;
int vector[MAXSIZE];
int pCount = 0;
void merge(int array[], int start, int middle, int end) {
    int s1 = start;
    int s2 = middle + 1;
    int rCount = 0;
    for (int i = start; i <= end; i ++) {
        vector[i] = array[i];
    }
    int pos = start;
    while (pos <= end) {
        if (s1 > middle || s2 > end) {
            if (s2 > end) {
                while (pos <= end) {
                    array[pos++] = vector[s1++];
                    pCount += rCount;
                }
            } else {
                pos = end + 1;
            }
        } else {
            if (vector[s1] <= vector[s2]) {
                array[pos++] = vector[s1++];
                pCount += rCount;
            } else {
                array[pos++] = vector[s2++];
                rCount++;
            }
        }
    }
}
void mergeSort(int array[], int start, int end) {
    if (start == end) {
        return;
    }
    int middle = (start + end) / 2;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
}
//int main() {
//    int a[MAXSIZE];
//    for (int i = 0; i < MAXSIZE; i++) {
//        a[i] = MAXSIZE - i;
//    }
//    mergeSort(a, 0, MAXSIZE - 1);
//    cout << pCount << endl;
//    return 0;
//}
