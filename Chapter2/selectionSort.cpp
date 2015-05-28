//
//  selectionSort.cpp
//  Algothrim
//
//  Created by 李思良 on 15/5/27.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace::std;

template <class T>
bool selectionSort(T array[], int length) {
    if (length <= 0) {
        return false;
    }
    for (int i = 0; i < length-1; i++) {
        for (int j = i + 1; j < length; j ++) {
            if (array[i] > array[j]) {
                T key = array[i];
                array[i] = array[j];
                array[j] = key;
            }
        }
    }
    return true;
}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    int a[6] = {1,3,4,2,6,7};
//    if (selectionSort(a, 6)) {
//        for (int i = 0; i < 6; i++) {
//            cout << a[i] << " ";
//        }
//    }
//    return 0;
//}