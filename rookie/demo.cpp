#include<iostream>
#include<vector>

using namespace std;


// ȫ�ֱ���
int g_numCount = 0;


class Solution {
public:
	// @��ʧ������ - hash��λ����  https://leetcode.cn/problems/missing-number-lcci/submissions/
	int missingNumber(std::vector<int>& nums) {
		// λ�����������ͬ���������ֽ��� ^ ����֮������� = 0
		// ��nums��������(n)�������Ȼ���ٴ�0 ~ n��n+1�����ݣ������ٳ������Ǹ����������
		// ���� 0 ~ n ��ǰ��� nums ��������ݽ���ƥ����������ʣ��һ����ʧ������
		int num = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			num ^= nums[i];
		}
		for (size_t i = 0; i <= nums.size(); i++) {
			num ^= i;
		}
		return num;
	}

	// �������� https://leetcode.cn/problems/missing-number-lcci/submissions/
	void rotate(vector<int> nums, int k) {
		int size = nums.size();
		k = k % size;
		if (k == 0 || size < 2) return;

		// 1234567 3
		// 
		// �ⷨ1��
		// �ռ任ʱ�� �ȶ�k����ȡģ���� k = k % size;
		// Ȼ���� [size - k ~ size - 1] ������(5 ~ 7)
		// Ȼ����� (size - k,0] (4, 3, 2, 1) ����Ų�� 1231234
		// Ȼ���[0, k)���������ռ����������
		vector<int> tmp;
		for (int i = size - k; i < size;i++) {
			tmp.push_back(nums[i]);
		}

		for (int i = size - k - 1; i >= 0; i--) {
			nums[i + k] = nums[i];
		}
		for (int i = 0; i < k; i++) {
			nums[i] = tmp[i];
		}

		// �ⷨ2
		// ��������
		// [0, size -k) [size - k, size)  [0, size)
	}

	// �Ƴ�ָ��ָ��λ�� https://leetcode.cn/problems/remove-element/
	int removeElement(vector<int>& nums, int val) {
		size_t pos = 0, cur = 0;

		while (cur < nums.size()) {
			if (nums[cur] != val) {
				nums[pos++] = nums[cur];
			}
			cur++;
		}
		return pos;
	}

	// ��������ɾ���ظ�����  https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) {
			return nums.size();
		}

		// ˼·������
		// posָ���һ�� curָ��ڶ���
		// cur�ӵ�һ����ʼ�ߵ����һ����
		// ��� pos == cur �� cur++
		// ��� pos != cur �� ++pos = cur
		// ����++pos(posΪ�±꣬Ҫ+1)

		size_t pos = 0, cur = 1;
		while (cur < nums.size()) {
			if (nums[pos] != nums[cur]) {
				nums[++pos] = nums[cur];
			}
			cur++;
		}
		return ++pos;
	}

	// �ϲ������������� 
	// �¿�һ�����飬˫ָ��ָ��������Ϸ���飬�Ƚ�С�ķ��¿������飬Ȼ��++ ѭ��ֱ������һ�����꣬Ȼ���ֲ�
};


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

// ��ϰ
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




//int main() {
int cppmain() {
	cout << "this is damo main fuc" << endl;
	// cur
	// 1  1  2  2  3  3  3
	// pos
	return 0;
}