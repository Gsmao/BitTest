#include"main.h"

using namespace std;

int g_numCount = 0;

// ð������
void bobbleSearch(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (arr[j - 1] > arr[j]) {
				//���򣬴��������
				//swap(arr+j-1, arr+j)
			}
		}
	}
	
}

// ����������ֲ���
int binarySearch(int *arr, int targe, int size) {
	int l = 0;
	int r = size - 1;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (arr[mid] < targe) {
			l = mid + 1;
		}
		else if (arr[mid] > targe) {
			r = mid - 1;
		}
		else {
			return arr[mid];
		}
	}
	return -1;
}



// �ݹ��ʱ�临�Ӷ�
int fac(int n) {
	g_numCount++;

	if (n == 1) return 1;
	return fac(n - 1) * n;
}

void func() {
	// ʱ�临�Ӷȣ��򵥵���˵����һ��������ִ�д���
	// O(n2) O(2n) O(1)
	int arrayCount = 10;
	for (int i = 0; i < arrayCount; i++) {
		for (int j = 0; j < arrayCount; j++) {
			cout << " O(n2)-> ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2 * arrayCount; i++) {
		cout << " O(2n)-> ";
	}
	cout << endl;
	cout << endl;

	int m = 10;
	while (m--) {
		cout << " O(m)-> ";
		// O(1)/O(m)
	}
	cout << endl;
}


void swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void damoMain() {
	
}