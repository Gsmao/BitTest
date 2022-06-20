#include"list.h"

void listPrintln(listNode* ps) {
	assert(ps != NULL);
	while (ps != NULL) {
		printf("%d-> ", ps->val);
		ps = ps->next;
	}
	printf("NULL\n");
}

listNode* createNode(dataType x) {
	// 错误写法(在栈上创建结构体，退出函数会被销毁)
	//listNode node = {NULL, x}; return &node;

	// 正确写法：在堆上申请空间
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if (node == NULL) {
		printf("malloc error");
		exit(1);
	}
	else {
		node->val = x;
		node->next = NULL;// 如果忽视了这一行 这里会是随机值，把随机值当成地址去解引用就会报错
		return node;
	}
}

void listPushBack(listNode** pphead, dataType x) {
	assert(pphead != NULL);

	if (*pphead == NULL) {
		*pphead = createNode(x);
	}
	else {
		listNode* cur = *pphead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = createNode(x);
	}
}

void listPushFront(listNode** pphead, dataType x) {
	assert(pphead != NULL);

	if (*pphead == NULL) {
		*pphead = createNode(x);
	}
	else {
		listNode* node = createNode(x);
		node->next = *pphead;
		*pphead = node;
	}
}

void listPopBack(listNode** pphead) {
	if(pphead == NULL) return;

	listNode* cur = *pphead;
	if (cur->next == NULL) {
		free(cur);
		*pphead = NULL;
	}
	else {
		listNode* prev = NULL;
		while (cur->next != NULL) {
			prev = cur;
			cur = cur->next;
		}
		// 遍历结束之后 cur 指向最后一个节点，释放， prev指向倒数第二个
		free(cur);
		prev->next = NULL;
	}
}

void listPopFront(listNode** pphead) {
	if (pphead == NULL) return;

	assert(*pphead != NULL);
	// 多个节点和一个节点
	listNode* cur = *pphead;

	/*if (cur->next == NULL) {
		free(cur);
		*pphead = NULL;
	}
	else {
		listNode* next = cur->next;
		free(cur);
		*pphead = next;
	}*/
	// 通过以上代码可以发现 一个节点和多个节点可以合并处理 cur->next = null 也是修改phead

	listNode* next = cur->next;
	free(cur);
	*pphead = next;
}

listNode* listPosFind(listNode* phead, dataType x) {
	listNode* cur = phead;
	while (cur != NULL) {
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void listInsertBefore(listNode** pphead, listNode* pos, dataType x) {
	assert(pphead != NULL);
	assert(pos != NULL);

	if (pos == *pphead) {
		listPushFront(pphead, x);
	}
	else {
		// 往中间插入
		listNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		};
		listNode* node = createNode(x);
		prev->next = node;
		node->next = pos;
	}
}

void listInsertAfter(listNode** pphead, listNode* pos, dataType x) {
	listNode* node = createNode(x);
	node->next = pos->next;
	pos->next = node;
}

void listErase(listNode** pphead, listNode* pos) {
	assert(pphead != NULL);
	
	if (*pphead == pos) {
		return listPopFront(pphead);
	}
	listNode* prev = *pphead;
	while (prev->next != pos) {
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
}

void listEraseAfter(listNode* pos) {
	if (pos->next != NULL) {
		listNode* next = pos->next->next;
		free(pos->next);
		pos->next = next;
	}
}

int listSize(listNode* phead) {
	listNode* cur = phead;
	int size = 0;
	while (cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}

bool listEmpty(listNode* phead) {
	return phead == NULL;
}

// 链表相关练习题

// 移除链表元素-203 https://leetcode.cn/problems/remove-linked-list-elements/
listNode* removeElements(listNode* head, int val) {
	listNode* cur = head;
	listNode* prev = NULL;

	while (cur != NULL) {
		// 如果相等，则删除cur prev 指向下一个指针
		if (cur->val == val) {
			// 正常情况 prev 非空，指向cur->next
			if (prev != NULL) {
				prev->next = cur->next;
				// prev 不能等于cur，cur已经被删除了
				cur = cur->next;
			}
			// prev 为空 
			else {
				head = cur->next;
				// 第一个节点就是val，head挪到后面去
				// cur也往后挪动 但是prev要继续指向null
				prev = NULL;
				cur = cur->next;
			}
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

// 反转链表-206 https://leetcode.cn/problems/reverse-linked-list/
struct ListNode* reverseList(struct ListNode* head) {
	// 1 - 2 - 3
	// 这个题的核心思想就是 前中后三个指针要玩明白
	// 1：先保存cur当前指针的next下一个地址（因为马上要改）
	// 2：然后改成 prev 指向的地址
	// 3：prev 就可以改成 cur（下一个地址的prev）
	// 4：cur 改成 next，向后移动
	// 要保证顺序不能乱
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = head;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}


int main() {
	listNode* phead = NULL;

	listPushFront(&phead, 1);
	listPushFront(&phead, 2);
	listPushFront(&phead, 3);
	listPrintln(phead);


	/*listPushBack(&phead, 1);
	listPushBack(&phead, 2);
	listPushBack(&phead, 3);
	listPushBack(&phead, 4);
	listPushBack(&phead, 5);
	listPrintln(phead);

	listPushFront(&phead, 0);
	listPrintln(phead);*/

	//listPopBack(&phead);
	//listPrintln(phead);

	listNode* node = listPosFind(phead, 2);
	node->val = 100;
	listPrintln(phead);

	listNode* node1 = listPosFind(phead, 100);
	listInsertBefore(&phead, node1, 99);
	listPrintln(phead);

	listInsertAfter(&phead, node1, 101);
	listPrintln(phead);

	//listErase(&phead, node1);
	//listPrintln(phead);


	//listEraseAfter(&phead, node1);
	//listPrintln(phead);

	return 0;
}