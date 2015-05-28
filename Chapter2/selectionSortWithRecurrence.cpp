//
//  selectionSortWithRecurrence.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/28.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
void sort(T array[], int length) {
    if (length == 1) {
        return;
    }
    sort(array, length - 1);
    int i;
    T key = array[length - 1];
    for (i = length - 2; i >= 0; i--) {
        if (array[i] > key) {
            array[i+1] = array[i];
        } else
            break;
    }
    array[i + 1] = key;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[6] = {9,3,4,2,6,7};
    sort(a, 6);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    return 0;
}