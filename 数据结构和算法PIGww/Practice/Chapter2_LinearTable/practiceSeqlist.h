//
//  PracticeSeqlist.h
//  DataStructure
//
//  Created by 官啸鹏 on 2020/6/26.
//  Copyright © 2020 PIGww. All rights reserved.
//

#ifndef practiceSeqlist_h
#define practiceSeqlist_h

//  1.从顺序表中删除具有最小值（假设唯一），并由函数返回被删元素的值，空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
bool DeleteMinElem(SeqList &L,ElemType &e){
    if(L.length==0){
        cout<<"顺序表为空，操作不合法！"<<endl;
        return false;
    }
    else{
        int fla=0;
        int i;
        for(i=0;i<L.length;i++){
            if(e>L.data[i]){
                fla=i;
                e=L.data[i];
            }
        }
        printf("最小值是：%d\n",e);
        L.data[fla]=L.data[L.length-1];
        L.length--;
        return true;
    }
}

//  2.设计一个高效算法，讲顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
void ListInverseGXP(SeqList &L){
    ElemType temp;
    int flag=0;
    for(int i=L.length-2;i>=0;i--){
        temp=L.data[i];
        for(int j=i;j<L.length-1;j++){
            L.data[j]=L.data[j+1];
            flag++;
        }
        L.data[L.length-1]=temp;
    }
    cout<<"时间复杂="<<flag<<endl;
}
// 王道答案 其实只需要从中间开始对称交换
void ListInverseWD(SeqList &L){
    ElemType temp;
    int flag=0;
    for(int i=0;i<L.length/2;i++){
        temp=L.data[i];
        L.data[i]=L.data[L.length-1-i];
        L.data[L.length-1-i]=temp;
        flag++;
    }
    cout<<"时间复杂="<<flag<<endl;
}


#endif /* PracticeSeqlist_h */
