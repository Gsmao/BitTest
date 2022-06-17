#include"main.h"
using namespace std;


// https://leetcode.cn/problems/missing-number-lcci/submissions/
// @��ʧ������ - hash��λ����
int Solution::missingNumber(vector<int>& nums) {
    // λ�����������ͬ���������ֽ��� ^ ����֮������� = 0
    // ��nums��������(n)�������Ȼ���ٴ�0 ~ n��n+1�����ݣ������ٳ������Ǹ����������
    // ���� 0 ~ n ��ǰ��� nums ��������ݽ���ƥ����������ʣ��һ����ʧ������
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

