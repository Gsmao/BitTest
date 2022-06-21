#include<iostream>
#include<vector>

using namespace std;


// 全局变量
int g_numCount = 0;


class Solution {
public:
	// @消失的数字 - hash、位运算  https://leetcode.cn/problems/missing-number-lcci/submissions/
	int missingNumber(std::vector<int>& nums) {
		// 位运算分析：相同的两个数字进行 ^ 操作之后互相抵消 = 0
		// 将nums所有数据(n)进行异或，然后再从0 ~ n（n+1条数据，多了少出来的那个）进行异或
		// 后面 0 ~ n 跟前面的 nums 里面的数据进行匹配抵消，最后剩下一个消失的数字
		int num = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			num ^= nums[i];
		}
		for (size_t i = 0; i <= nums.size(); i++) {
			num ^= i;
		}
		return num;
	}

	// 数组右旋 https://leetcode.cn/problems/missing-number-lcci/submissions/
	void rotate(vector<int> nums, int k) {
		int size = nums.size();
		k = k % size;
		if (k == 0 || size < 2) return;

		// 1234567 3
		// 
		// 解法1：
		// 空间换时间 先对k进行取模处理 k = k % size;
		// 然后复制 [size - k ~ size - 1] 的数据(5 ~ 7)
		// 然后倒叙从 (size - k,0] (4, 3, 2, 1) 往后挪动 1231234
		// 然后从[0, k)复制新增空间里面的数据
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

		// 解法2
		// 三次逆序
		// [0, size -k) [size - k, size)  [0, size)
	}

	// 移除指定指定位置 https://leetcode.cn/problems/remove-element/
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

	// 有序数组删除重复数据  https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) {
			return nums.size();
		}

		// 思路解析：
		// pos指向第一个 cur指向第二个
		// cur从第一个开始走到最后一个。
		// 如果 pos == cur 则 cur++
		// 如果 pos != cur 则 ++pos = cur
		// 返回++pos(pos为下标，要+1)

		size_t pos = 0, cur = 1;
		while (cur < nums.size()) {
			if (nums[pos] != nums[cur]) {
				nums[++pos] = nums[cur];
			}
			cur++;
		}
		return ++pos;
	}

	// 合并两个有序数组 
	// 新开一个数组，双指针指向两个游戏数组，比较小的放新开的数组，然后++ 循环直到其中一个走完，然后弥补
};


// 冒泡排序
void bobbleSearch(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (arr[j - 1] > arr[j]) {
				//升序，大的往后走
				//swap(arr+j-1, arr+j)
			}
		}
	}
	
}

// 升序数组二分查找
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

// 递归的时间复杂度
int fac(int n) {
	g_numCount++;

	if (n == 1) return 1;
	return fac(n - 1) * n;
}

// 练习
void func() {
	// 时间复杂度：简单的来说，是一个函数的执行次数
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