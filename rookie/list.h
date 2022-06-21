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
void listInsertBefore(listNode** pphead, listNode* pos, dataType x);
void listInsertAfter(listNode** pphead, listNode* pos, dataType x);

void listErase(listNode** pphead, listNode* pos);
void listEraseAfter(listNode* pos);

int listSize(listNode* phead);
bool listEmpty(listNode* phead);

