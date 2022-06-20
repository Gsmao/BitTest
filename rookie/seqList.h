#pragma once

#include<iostream>
#include<assert.h>

typedef int seqListType;

typedef struct seqList {
    seqListType* a;
    int size;//ʹ�õ�size
    int capatity;//����
} seqL;


// ˳����ʼ�� ���ٿռ䡢��ʼ������
void seqListInit(seqL* ps);

// �ͷ�˳��� ���ó�Ա����
void seqListDel(seqL* ps);

// ��ӡ˳���
void seqPrintln(seqL* ps);

// �������
void seqCheckCapatity(seqL* ps);

// β��
void seqListPushBack(seqL* ps, seqListType x);

// ͷ��
void seqListPushFront(seqL* ps, seqListType x);

// βɾ
void seqListPopBack(seqL* ps);

// ͷɾ
void seqListPopFront(seqL* ps);