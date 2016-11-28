//题目描述
//        编写程序。实现根据用户输入的三角形的边长，判定是何种三角形。
//
//输入
//        输入三个数（用逗号隔开），分别代表三角形的三条边。
//
//输出
///*判断三边是否构成三角形*/
//{
//　　/*如果三条边均相等，则输出为等边三角形：   printf("Equilateral triangle\n"); */
//　　else 　/*如果只有两条边相等，则输出为等腰三角形：printf("Isoceles triangle\n")*/
//　　else 　/*如果两边的平方和等于第三边平方，则输出为直角三角形：printf("Right-angled triangle\n")  */
//　　　　　else   /*输出为一般三角形：printf("General triangle\n");*/
//}
//else
///*输出不能构成三角形：printf("Can't make up of triangle\n"); */
//
//样例输入
//3,4,5
//样例输出
//        Right-angled triangle


#include <stdio.h>
#include <string.h>

int can_be_triangle(int a, int b, int c)
{
    return (a - b < c) && (a + b > c);
}

void solve(int a, int b, int c)
{
    if (can_be_triangle(a, b, c))
    {
        if (a == b && a == c)
        {
            printf("Equilateral triangle\n");
        }
        else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
        {
            printf("Isoceles triangle\n");
        }
        else if (a * a + b * b == c * c)
        {
            printf("Right-angled triangle\n");
        }
        else
        {
            printf("General triangle\n");
        }
    }
    else
    {
        printf("Can't make up of triangle\n");
    }
}

int main(void)
{
    int a, b, c;
    while (scanf("%d,%d,%d", &a, &b, &c) != EOF)
    {
        solve(a, b, c);
    }

    return 0;
}