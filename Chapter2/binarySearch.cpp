//
//  binarySearch.cpp
//  Algorithm
//
//  Created by 李思良 on 15/5/28.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
int binarySearch(T array[], T key, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (array[mid] == key) {
            return mid;
        }
        if (array[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}
//int main() {
//    int a[6] = {1,2,4,5,8,9};
//    cout << binarySearch(a, 4, 6) << endl << binarySearch(a, 3, 6) << endl;
//    return 0;
//}
