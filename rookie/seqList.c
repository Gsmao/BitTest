#include"seqList.h"


// 顺序表重点：
// 1: size 和 capatity 管理，但凡有一个没有控制好可能就会越界导致无法释放
// 2: 扩容、增删改查细节问题

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

// 容量检查（扩容）
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

// 尾插
void seqListPushBack(seqL* ps, seqListType x) {
	assert(ps);
	seqCheckCapatity(ps);
	// 尾插数据并++size
	ps->a[ps->size++] = x;
}

// 头插
void seqListPushFront(seqL* ps, seqListType x) {
	assert(ps);
	seqCheckCapatity(ps);

	// 后移
	int end = ps->size - 1; //数组形式 
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	};

	// 头插
	ps->a[0] = x;
	ps->size++;
}

// 尾删
void seqListPopBack(seqL* ps) {
	assert(ps);
	ps->size--;
}

// 头删
void seqListPopFront(seqL* ps) {
	assert(ps);

	// 前移
	int start = 1;
	while (start < ps->size) {
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}

// 指定位置插入
void seqListInsert(seqL* ps, int pos, seqListType x) {
	assert(ps);
	assert(pos < ps->size);//相等类似尾插
	seqCheckCapatity(ps);

	// 类似于指定位置的头插，需要后移
	int end = ps->size - 1;
	//无符号整形和整形进行比较的时候会被提升只无符号
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	
	//int end = ps->size;
	//// 这种写法比较稳妥
	//while (end > pos) {
	//	ps->a[end] = ps->a[end-1];
	//	end--;
	//}

	ps->a[pos] = x;
	ps->size++;
}

// 指定位置删除
void seqListErase(seqL* ps, int pos) {
	// 类似于头删，要往前移动
	assert(ps);
	assert(pos < ps->size);

	int start = pos + 1;
	while (start <= ps->size) {
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
	
	
	seqListInsert(&s, 0, 99);
	seqPrintln(&s);


	seqListErase(&s, 1);
	seqPrintln(&s);


	//seqListPopBack(&s);
	//seqListPopBack(&s);

	//seqListPopFront(&s);

	//seqPrintln(&s);

	//seqListDel(&s);



}