//
// Created by w@tch on 16/8/4.
//
/*
 * 题目描述
 * 输入一个链表，从尾到头打印链表每个节点的值。
 * 输入描述:
 *  输入为链表的表头
 * 输出描述:
 *  输出为需要打印的“新链表”的表头
 */

#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode *head)
    {
        vector<int> result;

        if (head != NULL)
        {
            result.insert(result.begin(), head->val);
            while (head->next != NULL)
            {
                result.insert(result.begin(), head->next->val);
                head = head->next;
            }
        }
        return result;
    }
};
