// 构造回文, 解决方案 2, 思路一样都是动态规划, 不过用的库函数不一样
// Created by w@tch on 16/7/23.
#include <string>
#include <iostream>
#include <algorithm> // reverse, max 函数均位于该头文件中
#include <vector>

using namespace std;

int main(void) {
    string s;
    string rs;
    while (cin >> s) {
        rs = s; // 复制
        reverse(rs.begin(), rs.end()); // 逆置

        // 动态规划初始化
        int length = s.size();
        vector<vector<int>> lcs(length + 1, vector<int>(length + 1, 0));

        /* 思路解释
         * 两个字符串 BDCABA 和 ABCBDAB, 字符串 BCBA 和 BDAB 都是是它们的最长公共子序列
         * lcs[i][j] 表示 s1 长度为 i, s2 长度为 j 时的最大公共子串长度
         * 现在已知 lcs[i - 1][j] 即 s1 长度为 i - 1, s2 长度为 j 时的最大公共子串长度
         * 而且已知 lcs[i][j - 1] 即 s1 长度为 i, s2 长度为 j - 1 时的最大公共子串长度
         * 当 s1 与 s2 同时增加一个字符之后, 判断 lcs[i][j] 的最大公共子串长度
         * 动态方程, 如果 s1 和 s2 增加的字符是相同的, 则最大公共子串长度可以 + 1, 否则最大公共子串长度为 lcs[i-1][j] 或 lcs[i][j-1]
        */
        for (int i = 1; i <= length; i++) {
            for (int j = 1; j <= length; j++) {
                if (s[i - 1] == rs[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else {
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }

        cout << length - lcs[length][length] << endl;
    }
}