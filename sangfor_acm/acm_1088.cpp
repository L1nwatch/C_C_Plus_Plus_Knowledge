//题目描述
//
//
//        从键盘输入一个整数n(98000<=n<=100000),统计1至n范围内素数的个数。
//
//质数又称素数。指在一个大于1的自然数中，除了1和此整数自身外，没法被其他自然数整除的数。换句话说，只有两个正因数（1和自己）的自然数即为素数。比1大但不是素数的数称为合数。1和0既非素数也非合数。
//
//输入
//        输入一个整数n(98000<=n<=100000)
//
//输出
//        素数的个数
//
//样例输入
//100000
//样例输出
//9592



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
    int counts = 0;
    for (int i = 1; i <= x; ++i)
    {
        if (is_prime_number(i))
        {
            ++counts;
        }
    }
    printf("%d", counts);

}

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        solve(n);
    }

    return 0;
}