#pragma once

#ifndef __MAIN_H__
#define __MAIN_H__
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
extern int g_numCount;


void damoMain();// damo主函數入口
void swap(int* a, int* b);

class Solution {
public:

    // https://leetcode.cn/problems/missing-number-lcci/submissions/
    // @消失的数字 - hash、位运算
    int missingNumber(std::vector<int>& nums);
    void rotate(std::vector<int> nums, int k);
};



#endif // !1
