#include"seqList.h"


void seqTest() {
	printf("this is seqTest func\n");
}

void seqListInit(seqL* ps) {
	assert(ps);
	ps->a = NULL;
	ps->capatity = ps->size = 0;
}

void seqListDel(seqL* ps) {
	assert(ps);
	if (ps->a != NULL) {
		free(ps->a);
	}
	ps->capatity = ps->size = 0;
}

// ������飨���ݣ�
void seqCheckCapatity(seqL* ps) {
	assert(ps);
	if (ps->size == ps->capatity) {
		int capatity = ps->capatity == 0 ? 4 : ps->capatity * 2;
		void * point = realloc(ps->a, capatity * sizeof(seqListType));
		if (point != NULL) {
			ps->a = (seqListType*)point;
			ps->capatity = capatity;
		}
		else {
			printf("realloc return null");
			exit(1);
		}
	}
}

void seqPrintln(seqL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

// β��
void seqListPushBack(seqL* ps, seqListType x) {
	assert(ps);
	seqCheckCapatity(ps);
	// β�����ݲ�++size
	ps->a[ps->size++] = x;
}

// ͷ��
void seqListPushFront(seqL* ps, seqListType x) {
	assert(ps);
	seqCheckCapatity(ps);

	// ����
	int end = ps->size - 1; //������ʽ 
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	};

	// ͷ��
	ps->a[0] = x;
	ps->size++;
}

// βɾ
void seqListPopBack(seqL* ps) {
	assert(ps);
	ps->size--;
}

// ͷɾ
void seqListPopFront(seqL* ps) {
	assert(ps);

	// ǰ��
	int start = 1;
	while (start < ps->size) {
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}

void seqMain() {
	seqL s;
	seqListInit(&s);

	seqListPushBack(&s, 1);
	seqListPushBack(&s, 2);
	seqListPushBack(&s, 3);

	seqListPushFront(&s, 4);
	seqListPushFront(&s, 5);

	seqPrintln(&s);

	seqListPopBack(&s);
	seqListPopBack(&s);

	seqListPopFront(&s);

	seqPrintln(&s);

	seqListDel(&s);

}