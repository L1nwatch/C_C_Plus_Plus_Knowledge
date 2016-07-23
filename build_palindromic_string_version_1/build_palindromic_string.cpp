// 题目: 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？输出需要删除的字符个数。
// Created by w@tch on 16/7/22.
// 腾讯的一道题, 用 Python 写超时了, 改用 C++ 写吧
#include <stdio.h>
#include <string.h>
#include "build_palindromic_string.h"


char *strrev(char *s) {
    if (s == NULL || s[0] == '\0')
        return s;

    for (char t, *p = s, *q = s + strlen(s) - 1; p < q; p++, q--) {
        t = *p;
        *p = *q;
        *q = t;
    }

    return s;
}

int dynamic_solve(char *s) {

    // 先求反串
    char *reverse_s = new char(strlen(s) * sizeof(char));
    strcpy(reverse_s, s);
    strrev(reverse_s);

    // 初始化
    int length = strlen(s);
    int dp[MAX_LENGTH][MAX_LENGTH] = {0};

    // 求最长公共子序列
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (s[i] == reverse_s[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];
            }
        }
    }

    return length - dp[length][length]; // 长度减去最长公共子序列即为所求
}

int this_main(void){
    return 0;
}