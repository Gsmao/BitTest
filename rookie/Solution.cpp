#include"main.h"
using namespace std;


// https://leetcode.cn/problems/missing-number-lcci/submissions/
// @消失的数字 - hash、位运算
int Solution::missingNumber(vector<int>& nums) {
    // 位运算分析：相同的两个数字进行 ^ 操作之后互相抵消 = 0
    // 将nums所有数据(n)进行异或，然后再从0 ~ n（n+1条数据，多了少出来的那个）进行异或
    // 后面 0 ~ n 跟前面的 nums 里面的数据进行匹配抵消，最后剩下一个消失的数字
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
        num ^= nums[i];
    }
    for (int i = 0; i <= nums.size(); i++) {
        num ^= i;
    }
    return num;
}

void Solution::rotate(vector<int> nums, int k) {
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

