//  数据结构：顺序表相关操作
//  seqtable.h
//  DataStructure
//
//  Created by 官啸鹏 on 2020/6/21.
//  Copyright © 2020 PIGww. All rights reserved.
//

//  InitList(&L):初始化表。构造一个空的线性表，分配内存空间。
//  DestroyList(&L):销毁操作。销毁线性表，并释放线性表L所占用的内存空间。
//  ListInsert(&L,i,e):插入操作。在表L中的第i个位置上插入指定元素e。
//  ListDelete(&L,i,&e):删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值。
//  LocateElem(L,e):按值查找操作。在表L中查找具有给定关键字值的元素。
//  GetElem(L,i):按位查找操作。获取表L中第i个位置的元素的值。
//  Length(L):求表长。返回线性表L的长度，即L中数据元素的个数。
//  PrintList(L):输出操作。按前后顺序输出线性表L的所有元素值。
//  Empty(L):判空操作。若L为空表，则返回true，否则返回false。
#ifndef seqtable_h
#define seqtable_h

using namespace std;
#include<stdlib.h>

#define MaxSize 10  //静态分配时使用
#define InitSize 10 //动态分配时使用
typedef int ElemType;

//  静态分配
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
//静态分配初始化
void InitListStatic(SqList &L){
    int i;
    for(i=0;i<MaxSize;i++)  L.data[i]=i;
    L.length=0;
}

//  动态分配
typedef struct{
    ElemType *data;
    int maxsize;
    int length;
} SeqList;
//  动态分配初始化
void InitList(SeqList &L){
    L.data=(ElemType *)malloc(InitSize * sizeof(ElemType));
    L.length=0;
    L.maxsize=InitSize;
}
//销毁
void Destroylist(SeqList &L){
    free(L.data);
    cout<<"成功删除顺序表！"<<endl;
}
//  动态分配添加动态数组的长度
void IncreaseSize(SeqList &L,int len){
    ElemType *p=L.data;
    L.data=(ElemType *)malloc((L.maxsize+len) * sizeof(ElemType));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.maxsize+=len;
    free(p);
}

//判断给定的位序是否在表中存在
bool JudgeI(SeqList L,int i,int len){
    if(i<1||i>len)return false;
    else return true;
}
//判断该表是否满
bool JudgeIsFull(SeqList L){
    if(L.length==L.maxsize)return false;
    else return true;
}
//插入元素
void ListInsert(SeqList &L,int i,ElemType elem){
    if(JudgeI(L, i, L.length+1)&&JudgeIsFull(L)){
        if(L.length==0){
            L.data[0]=elem;
            L.length++;
        }
        else{
            for(int j=L.length;j>=i;j--){
                L.data[j]=L.data[j-1];
            }
            L.data[i-1]=elem;
            L.length++;
        }
    }
    else cout<<"您的操作不合法！"<<endl;
}
//删除操作
void ListDelete(SeqList &L,int i,ElemType &e){
    if(JudgeI(L, i, L.length)){
        e=L.data[i-1];
        for(int j=i;j<L.length;j++){
            L.data[j-1]=L.data[j];
        }
        L.data[L.length]=0;
        L.length--;
        cout<<"删除操作完成"<<endl;
    }
    else cout<<"您的操作不合法"<<endl;
}
//按位查找
ElemType GetElem(SeqList L,int i){
    if(JudgeI(L, i, L.length)){
        return L.data[i-1];
    }
    else return 0;
}
//按值查找
int LocateElem(SeqList L,ElemType Elem){
    for(int i=1;i<=L.length;i++){
        if(L.data[i-1]==Elem)return i;
    }
    return 0;
}
//求表长
int length(SeqList L){
    return L.length;
}
//输出操作
bool judgebe(SeqList L,int beg,int end){
    if(beg<1||end<1||beg>L.length||end>L.length)return false;
    else return true;
}
void PrintList(SeqList L,int beg,int end){
    if(judgebe(L, beg, end)){
        int i;
        cout<<"当前顺序表第"<<beg<<"位到第"<<end<<"位显示：";
        for(i=beg-1;i<end-1;i++)cout<<L.data[i]<<"->";
        cout<<L.data[end-1]<<endl;
        cout<<"显示完成！"<<endl;
    }
    else cout<<"您的输入不合法，当前初值为："<<beg<<"，终值为"<<end<<endl;
}
//判空操作
bool EmptyList(SeqList L){
    if(L.length!=0)return true;
    else return false;
}

/*测试示例
// insert code here...
SeqList L;
InitList(L);
for(int i=0;i<8;i++){
    ListInsert(L, 1, i);
}
PrintList(L, 1, L.length);
cout<<"现在的表长是："<<length(L)<<endl;
cout<<"6在表中第"<<LocateElem(L, 6)<<"个元素"<<endl;
cout<<"5在表中第"<<LocateElem(L, 5)<<"个元素"<<endl;
cout<<"表中的第4个元素是"<<GetElem(L, 4)<<endl;
ElemType e=0;
ListDelete(L, 3, e);
cout<<"e="<<e<<endl;
PrintList(L, 1, L.length);
cout<<"现在的表长是："<<length(L)<<endl;
cout<<"6在表中第"<<LocateElem(L, 6)<<"个元素"<<endl;
cout<<"5在表中第"<<LocateElem(L, 5)<<"个元素"<<endl;
cout<<"表中的第4个元素是"<<GetElem(L, 4)<<endl;
Destroylist(L);
*/

#endif /* seqtable_h */
