//题目描述
//        从键盘输入2个操作数和运算符，用switch语句实现两个数的加、减、乘、除运算。
//
//输入
//        按照运算表达式的顺序输入两个操作数和运算符，如2+3或88-2或25/6或21.7*3。操作数为双精度浮点型数据，运算符为'+'或'-'或'*'或'/'。
//
//输出
//        输出运算结果，结果为双精度浮点型数据。输出数据后要换行。
//
//样例输入
//21.7*7
//样例输出
//151.900000


#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;

void solve(char *question)
{
    int length = strlen(question);
    char *number1 = &question[0];
    char *number2;
    char operation;

    for (int i = 0; i < length; ++i)
    {
        if (question[i] == '+' || question[i] == '-' || question[i] == '*' || question[i] == '/')
        {
            operation = question[i];
            number2 = &question[i + 1];
            question[i] = '\0';
        }
    }
    double a = atof(number1);
    double b = atof(number2);

    switch (operation)
    {
        case '+':
            printf("%f\n", a + b);
            break;
        case '-':
            printf("%f\n", a - b);
            break;
        case '*':
            printf("%f\n", a * b);
            break;
        case '/':
            printf("%f\n", a / b);
            break;

    }

}

int main(void)
{
    char question[10000];
    while (scanf("%s", question) != EOF)
    {
        solve(question);
    }


    return 0;
}