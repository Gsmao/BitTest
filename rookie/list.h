#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int dataType;

typedef struct ListNode {
    struct ListNode* next;
    dataType val;
} listNode;


void listMain();

// 打印链表
void listPrintln(listNode* phead);
// 创建新节点
listNode* createNode(dataType x);
// 尾插
void listPushBack(listNode** pphead, dataType x);
// 头插
void listPushFront(listNode** pphead, dataType x);
// 尾删
void listPopBack(listNode** pphead);
// 头删
void listPopFront(listNode** pphead);
// 查某个数值
listNode* listPosFind(listNode* phead, dataType x);
// 在pos位置插入  1->2->3
void listInsertBefore(listNode** pphead, listNode* pos, dataType x);
void listInsertAfter(listNode** pphead, listNode* pos, dataType x);

void listErase(listNode** pphead, listNode* pos);
void listEraseAfter(listNode* pos);

int listSize(listNode* phead);
bool listEmpty(listNode* phead);

