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
	// ����д��(��ջ�ϴ����ṹ�壬�˳������ᱻ����)
	//listNode node = {NULL, x}; return &node;

	// ��ȷд�����ڶ�������ռ�
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if (node == NULL) {
		printf("malloc error");
		exit(1);
	}
	else {
		node->val = x;
		node->next = NULL;// �����������һ�� ����������ֵ�������ֵ���ɵ�ַȥ�����þͻᱨ��
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
		// ��������֮�� cur ָ�����һ���ڵ㣬�ͷţ� prevָ�����ڶ���
		free(cur);
		prev->next = NULL;
	}
}

void listPopFront(listNode** pphead) {
	if (pphead == NULL) return;

	assert(*pphead != NULL);
	// ����ڵ��һ���ڵ�
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
	// ͨ�����ϴ�����Է��� һ���ڵ�Ͷ���ڵ���Ժϲ����� cur->next = null Ҳ���޸�phead

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
		// ���м����
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

// ���������ϰ��

// �Ƴ�����Ԫ��-203 https://leetcode.cn/problems/remove-linked-list-elements/
listNode* removeElements(listNode* head, int val) {
	listNode* cur = head;
	listNode* prev = NULL;

	while (cur != NULL) {
		// �����ȣ���ɾ��cur prev ָ����һ��ָ��
		if (cur->val == val) {
			// ������� prev �ǿգ�ָ��cur->next
			if (prev != NULL) {
				prev->next = cur->next;
				// prev ���ܵ���cur��cur�Ѿ���ɾ����
				cur = cur->next;
			}
			// prev Ϊ�� 
			else {
				head = cur->next;
				// ��һ���ڵ����val��headŲ������ȥ
				// curҲ����Ų�� ����prevҪ����ָ��null
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

// ��ת����-206 https://leetcode.cn/problems/reverse-linked-list/
struct ListNode* reverseList(struct ListNode* head) {
	// 1 - 2 - 3
	// �����ĺ���˼����� ǰ�к�����ָ��Ҫ������
	// 1���ȱ���cur��ǰָ���next��һ����ַ����Ϊ����Ҫ�ģ�
	// 2��Ȼ��ĳ� prev ָ��ĵ�ַ
	// 3��prev �Ϳ��Ըĳ� cur����һ����ַ��prev��
	// 4��cur �ĳ� next������ƶ�
	// Ҫ��֤˳������
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