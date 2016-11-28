//题目描述
//        判断正整数x是否为素数。
//
//质数又称素数。指在一个大于1的自然数中，除了1和此整数自身外，没法被其他自然数整除的数。换句话说，只有两个正因数（1和自己）的自然数即为素数。比1大但不是素数的数称为合数。1和0既非素数也非合数。
//
//输入
//        先输入一个整数n（表示后面要输入n个测试数据）；
//
//然后输入n个测试数据，每个测试数据是一个正整数x。
//
//输出
//        与n个输入的正整数x相对应，输出判断结果。如果是素数，输出"Yes"，不是素数，输出"No"。
//
//样例输入
//5
//7
//8
//795
//181
//888
//样例输出
//        Yes
//No
//        No
//Yes
//        No



#include <stdio.h>
#include <math.h>

int is_prime_number(int x)
{
    if (x == 1 || x == 0)
    {
        return 0;
    }
    else if (x == 2)
    {
        return 1;
    }

    double double_x = x * 1.0;
    for (int i = 2; i < sqrt(double_x) + 1; ++i)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void solve(int x)
{
    if (is_prime_number(x))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main(void)
{
    int x;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        solve(x);
    }

    return 0;
}