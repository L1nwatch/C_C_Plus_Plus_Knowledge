//题目描述
//        从键盘输入一学生某科目成绩x，判断学生成绩等级。如果x<0或x>100，输出"Error"；如果90<=x<=100，等级为'A'；如果80<=x<90，等级为'B'；如果在70<=x<80，等级为'C'；如果60<=x<70，等级为'D'；如果成绩小于60，等级为'E'。
//
//输入
//        输入成绩x，x为单精度浮点型数据。
//
//输出
//        输入数据小于0或大于100，输出字符串"Error"；
//
//输入数据在0到100之间，输出等级，等级为一字符。或为'A'；或为'B'；或为'C'；或为'D'；或为'E'。
//
//样例输入
//99.99
//样例输出
//        A


#include <stdio.h>

void solve(double score)
{
    if (score >= 90 && score <= 100)
    {
        printf("A\n");
    } else if (score >= 80 && score < 90)
    {
        printf("B\n");

    } else if (score >= 70 && score < 80)
    {
        printf("C\n");
    } else if (score >= 60 && score < 70)
    {
        printf("D\n");
    } else if (score >= 0 && score < 60)
    {
        printf("E\n");
    } else
    {
        printf("Error\n");
    }

}

int main(void)
{
    double score = 0;
    while (scanf("%lf", &score) != EOF)
    {
        solve(score);
    }


    return 0;
}