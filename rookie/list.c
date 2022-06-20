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

// ����
void listInsert(listNode** pphead, listNode* pos, dataType x) {
	listNode* cur = *pphead;
	listNode* prev = NULL;

	if (cur == pos) {
		return listPushFront(pphead, x);
	}
	else {
		// ���м����
		while (cur != pos) {
			prev = cur;
			cur = cur->next;
		};

		listNode* node = createNode(x);
		prev->next = node;
		node->next = pos;
	}
}

void listErase(listNode** pphead, listNode* pos);


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

// �Ƴ�����Ԫ�� https://leetcode.cn/problems/remove-linked-list-elements/
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
	listInsert(&phead, node1, 99);
	listPrintln(phead);

	return 0;
}