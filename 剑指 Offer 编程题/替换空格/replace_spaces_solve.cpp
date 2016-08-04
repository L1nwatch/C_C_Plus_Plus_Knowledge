//
// Created by w@tch on 16/7/27.
//
/*
 * 题目描述:
 *     请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

#include "string.h"
#include "stdio.h"

//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
    void replaceSpace(char *str, int length)
    {
        // 这其实可以忽略
        if (str == NULL || length < 0)
        {
            return;
        }

        // 遍历一遍数一下有多少个空格
        int space_numbers = 0;
        int i = 0;
        while (str[i] != '\0') // 注意不能数 length, 否则会越界
        {
            if (str[i++] == ' ')
            {
                ++space_numbers;
            }
        }

        // 计算替换后的长度
        int raw_length = strlen(str);
        int after_replace_length = raw_length + space_numbers * 2;

        // 定义指针
        int point_to_raw, point_to_new;
        point_to_new = after_replace_length;
        point_to_raw = raw_length;

        // while 循环遍历, 条件是两个索引值相等
        // while 结构体实现替换操作
        while (point_to_new != point_to_raw)
        {
            if (str[point_to_raw] != ' ')
            {
                str[point_to_new] = str[point_to_raw];
                --point_to_new;
            }
            else
            {
                str[point_to_new] = '0';
                str[point_to_new - 1] = '2';
                str[point_to_new - 2] = '%';
                point_to_new -= 3;
            }
            --point_to_raw;
        }

    }
};

int main(void)
{
    char *raw = new char[18];
    raw = strcpy(raw, "We Are Happy");
    Solution solution = Solution();

    solution.replaceSpace(raw, 18);
    printf("%s\n", raw);

    return 0;
}