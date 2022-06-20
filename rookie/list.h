#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef int dataType;

typedef struct ListNode {
    struct ListNode* next;
    dataType val;
} listNode;


// ��ӡ����
void listPrintln(listNode* phead);
// �����½ڵ�
listNode* createNode(dataType x);
// β��
void listPushBack(listNode** pphead, dataType x);
// ͷ��
void listPushFront(listNode** pphead, dataType x);
// βɾ
void listPopBack(listNode** pphead);
// ͷɾ
void listPopFront(listNode** pphead);
// ��ĳ����ֵ
listNode* listPosFind(listNode* phead, dataType x);
// ��posλ�ò���  1->2->3
void listInsert(listNode** pphead, listNode* pos, dataType x);
void listErase(listNode** pphead, listNode* pos);

int listSize(listNode* phead);
bool listEmpty(listNode* phead);