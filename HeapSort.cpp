//
//  HeapSort.cpp
//  Algorithm
//
//  Created by 李思良 on 15/7/14.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <iostream>

using namespace std;

void maxHeapify(int array[], int i, int size) {
    int l, r, largest;
    while (2*i+1 < size) {
        largest = i;
        l = 2*i+1;
        r = 2*i+2;
        if (l < size && array[l] > array[i]) {
            largest = l;
        } else
            largest = i;
        if (r < size && array[r] > array[largest]) {
            largest = r;
        }
        if (largest != i) {
            int tmp = array[i];
            array[i] = array[largest];
            array[largest] = tmp;
            i = largest;
        } else
            break;
    }
}


void createHeap(int array[], int size) {
    for (int i = size/2-1; i >= 0; i--) {
        maxHeapify(array, i, size);
    }
}

void sortArray(int array[], int size) {
    createHeap(array, size);
    int tmp = 0;
    for (int i = size - 1; i > 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        maxHeapify(array, 0, --size);
    }
}

//int main() {
//    int array[100];
//    for (int i = 0; i < 100; i ++) {
//        array[i] = i%50;
//    }
//    sortArray(array, 100);
//    for (int i = 0; i < 100; i++) {
//        cout << array[i] << endl;
//    }
//    return 0;
//}