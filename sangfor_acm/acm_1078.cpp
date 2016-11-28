/*
题目描述
输入一个其值不大于32767的正整数，将各位数字分离出来，依次显示。

输入
不大于32767的正整数

输出
输出正整数的各位数字，各位数字间用逗号隔开，最后一位数字之后换行。

样例输入
32767
样例输出
3,2,7,6,7

 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[9] = {'\0'};
    while (scanf("%s", &a) != EOF)
    {
        int length = strlen(a);
        for (int i = 0; i < length; ++i)
        {
            putchar(a[i]);
            if (i != length - 1)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}