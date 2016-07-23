//
// Created by w@tch on 16/7/21.
//
//#include "stdio.h"
//#include "build_palindromic_string.h"

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

char *strrev(char *s) {
    if (s == NULL || s[0] == '\0')
        return s;

    for (char t, *p = s, *q = s + strlen(s) - 1; p < q; p++, q--) {
        t = *p;
        *p = *q;
        *q = t;
    }

    return s;
}

int dynamic_solve(char *s) {
    // 先求反串
    char *reverse_s = new char(strlen(s) * sizeof(char));
    strcpy(reverse_s, s);
    strrev(reverse_s);

    // 初始化
    int length = strlen(s);
    int i, j;
    int dp[MAX_LENGTH][MAX_LENGTH] = {0};

    // 求最长公共子序列
    for (i = 0; i < length; ++i) {
        for (j = 0; j < length; ++j) {
            if (s[i] == reverse_s[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];
            }
        }
    }

    return length - dp[length][length]; // 长度减去最长公共子序列即为所求
}

int main(void) {
//    FILE *f = fopen("/Users/L1n/Desktop/C_C++ Projects/C_C_Plus_Plus_Knowledge/data.txt", "r");
    FILE *f = fopen("data.txt", "r");
    if (f != NULL) {
        char s[MAX_LENGTH] = {0};
        while (fscanf(f, "%s", s) != EOF) {
            printf("%d\n", dynamic_solve(s));
        }
    }


    return 0;
}

/*
int main() {
    char s[MAX_LENGTH] = {0};
    while (scanf("%s", s) != EOF) {
        printf("%d\n", dynamic_solve(s));
    }
//    char s[] = "abcdefg";
//    char s[] = "zgtklhfzomzjckwmluvivvcmhjrwkuvcjrxojobpdedpamdshcwwsetfbacvonecrdvugeibglvhxuymjvoryqjwullvzglqazxrdmczyvbgakjagttrezmvrlptiwoqkrtxuroeqmryzsgokopxxdpbejmtwvpnaqrgqladdszhdwxfckmewhdvihgvacueqhvwvjxoitlpfrckxkuksaqzjpwgoldyhugsacflcdqhifldoaphgdbhaciixouavqxwlghadmfortqacbffqzocinvuqpjthgekunjsstukeiffjipzzabkuiueqnjgkuiojwbjzfynafnlcaryygqjfixaoeowhkxkbsnpsvnbxuywfxbnuoemxynbtgkqtjvzqikbafjnpbeirxxrohhnjqrbqqzercqcrcswojyylunuevtdhamlkzqnjrzibwckbkiygysuaxpjrgjmurrohkhvjpmwmmtpcszpihcntyivrjplhyrqftghglkvqeidyhtmrlcljngeyaefxnywpfsualufjwnffyqnpitgkkyrbwccqggycrvoocbwsdbftkigrkcbojuwwctknzzmvhbhbfzrqwzllulbabztqnznkqdyoqnrxhwavqhzyzvmmmphzxbikpharseywpfsqyybkynwbdrgfsaxduxojcdqcjuaywzbvdjgjqtoffasiuhvxcaockebkuxpiomqmtvsqhnyxfjceqevqvnapbk";
}
*/