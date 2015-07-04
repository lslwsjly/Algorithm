//
//  prob4-2.cpp
//  Algorithm
//
//  Created by 李思良 on 15/6/30.
//  Copyright (c) 2015年 lsl. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 6000;
const int LACK = 912;
int data[MAX];

//记录需要访问的数组编号
int searchIndex[MAX];

int size = MAX;
int currentSize = size;

//记录缺失数前currentIndex位的值
int remainder = 0;
//当前该扫描的位置
int currentIndex = 0;

//记录待搜索数组中未缺失时第currentIndex位0比1多几个（0个或1个）
int getValue() {
    return (currentSize+1) % 2;
}

//读取第i个数的第j位，数的最右侧为第0位
int readNum(int i, int j) {
    return (data[searchIndex[i]] >> j) % 2;
}

void createData() {
    int val = 0;
    for (int i = 0; i < MAX; i++) {
        data[i] = val++;
        if (val == LACK) {
            val++;
        }
        searchIndex[i] = i;
    }
}

//int main() {
//    createData();
//    while (1 << (currentIndex+1) < MAX) {
//        int cc = 0;
//        for (int i = 0; i < currentSize; i++) {
//            //需要在下一次检查的数
//            if (readNum(i, currentIndex) == 0) {
//                cc++;
//            } else {
//                cc--;
//            }
//        }
//        int x;
//        if (cc == getValue()-1) {
//            x = 0;
//        } else {
//            x = 1;
//        }
//        remainder += x * (1 << currentIndex);
//        int nIndex = 0;
//        for (int i = 0; i < currentSize; i++) {
//            //需要在下一次检查的数
//            if (readNum(i, currentIndex) == x) {
//                searchIndex[nIndex ++] = searchIndex[i];
//            }
//        }
//        //待搜索数组规模变小
//        currentSize = nIndex;
//        currentIndex ++;
//    }
//    cout << remainder << endl;
//    return 0;
//}
