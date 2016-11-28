//
// Created by w@tch on 16/11/26.
//

/*
题目描述
从键盘输入一个字符，判断它是字母、数字或其它字符。

输入
从键盘输入一个字符。注意：不用提示信息。

输出
若输入的字符是字母，输出"alphabetic character"；

若输入的字符是数字，输出"digital character"；

若输入的字符是其它字符，输出"other character"；

样例输入
6
样例输出
digital character
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a = '\0';
    while (scanf("%c", &a) != EOF)
    {
        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
        {
            printf("alphabetic character");
        } else if (a >= '0' && a <= '9')
        {
            printf("digital character");
        }
        else
        {
            printf("other character");
        }
    }

    return 0;
}