/*
 *
题目描述
给出两个整数A,B

求A+B的结果

输入
A，B两个整数

0≤A, B≤1018

输出
一个整数C
样例输入
1 1
样例输出
2
 */

#include <stdio.h>
int main(){
    long a,b;
    while(scanf("%ld %ld",&a, &b) != EOF)
        printf("%ld\n",a+b);
    return 0;
}