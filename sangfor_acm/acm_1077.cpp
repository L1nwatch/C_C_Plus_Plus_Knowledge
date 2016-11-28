/*
题目描述
编写程序，给出一个其值不超过12345678的正整数，求出它是几位数。

输入
不超过12345678的正整数.

输出
该正整数的位数

样例输入
31888
样例输出
5

 */

#include <stdio.h>


int main(void)
{
    char a[9] = {'\0'};
    while (scanf("%s", &a) != EOF)
    {
        int counts = 0;
        for (int i = 0; i < 8; ++i)
        {
            if (a[i] < '9' && a[i] > '0')
            {
                counts += 1;
                a[i] = '\0';
            }
        }
        printf("%d", counts);
    }

    return 0;
}