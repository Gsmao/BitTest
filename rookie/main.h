#pragma once

#ifndef __MAIN_H__
#define __MAIN_H__
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
extern int g_numCount;


void damoMain();// damo���������
void swap(int* a, int* b);

class Solution {
public:

    // https://leetcode.cn/problems/missing-number-lcci/submissions/
    // @��ʧ������ - hash��λ����
    int missingNumber(std::vector<int>& nums);
    void rotate(std::vector<int> nums, int k);
};



#endif // !1
