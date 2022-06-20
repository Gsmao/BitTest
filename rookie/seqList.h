#pragma once

#include<iostream>
#include<assert.h>

typedef int seqListType;

typedef struct seqList {
    seqListType* a;
    int size;//使用的size
    int capatity;//容量
} seqL;


// 顺序表初始化 开辟空间、初始化变量
void seqListInit(seqL* ps);

// 释放顺序表 重置成员变量
void seqListDel(seqL* ps);

// 打印顺序表
void seqPrintln(seqL* ps);

// 检查容量
void seqCheckCapatity(seqL* ps);

// 尾插
void seqListPushBack(seqL* ps, seqListType x);

// 头插
void seqListPushFront(seqL* ps, seqListType x);

// 尾删
void seqListPopBack(seqL* ps);

// 头删
void seqListPopFront(seqL* ps);