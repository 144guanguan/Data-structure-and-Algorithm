//
//  main.cpp
//  数据结构和算法PIGww
//
//  Created by 官啸鹏 on 2020/6/27.
//  Copyright © 2020 PIGww. All rights reserved.
//

#include <iostream>
#include "LinearTable/seqtable.h"   //顺序表定义及相关操作
#include "TablePractice/table.h"    //idea
#include "Practice/Chapter2_LinearTable/practiceSeqlist.h"  //顺序表练习
using namespace std;

int main(int argc, const char * argv[]) {
    SeqList L;
    InitList(L);
    ElemType a[10]={10,23,32,34,12,24,45,55,22,100};
    for(int i=0;i<10;i++)ListInsert(L, 1, a[i]);
    PrintList(L, 1, L.length);
    ListInverseWD(L);
    PrintList(L, 1, L.length);
    Destroylist(L);
    return 0;
}
