//
//  insertSort.cpp
//  Algothrim
//
//  Created by 李思良 on 15/5/27.
//  Copyright (c) 2015年 lsl. All rights reserved.
//


#include <iostream>
using namespace std;

template <class T>
bool insertSort(T array[], int length) {
    if (length <= 0) {
        return false;
    }
    for (int j = 1; j < length; j++) {
        T key = array[j];
        int i = j - 1;
        while(i >=0 && array[i] > key) {
            array[i+1] = array[i];
            i --;
        }
        array[i+1] = key;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[6] = {1,3,4,2,6,7};
    if (insertSort(a, 6)) {
        for (int i = 0; i < 6; i++) {
            cout << a[i] << " ";
        }
    }
    return 0;
}