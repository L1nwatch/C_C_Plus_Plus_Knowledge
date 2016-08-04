//
// Created by w@tch on 16/8/4.
//
/*
 * 题目描述
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */

#include "stdio.h"
#include "vector"
//#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    struct TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in)
    {
        if (pre.size() > 0 && in.size() > 0)
        {
            TreeNode * root = new TreeNode(pre[0]);

            vector<int>::iterator root_position_in_order = find(in.begin(), in.end(), root->val);

            int left_length = root_position_in_order - in.begin();


            root->left = Solution().reConstructBinaryTree(
                    vector<int>(pre.begin() + 1, pre.begin() + left_length + 1),
                    vector<int>(in.begin(), root_position_in_order));
            root->right = Solution().reConstructBinaryTree(
                    vector<int>(pre.begin() + left_length + 1, pre.end()),
                    vector<int>(root_position_in_order + 1, in.end()));

            return root;
        }
        return NULL;
    }
};

void post_order_print(struct TreeNode *root)
{
    if (root != NULL)
    {
        post_order_print(root->left);
        post_order_print(root->right);
        printf("%d ", root->val);
    }
}

int main(void)
{
    vector<int> pre_oredr = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in_order = {4, 7, 2, 1, 5, 3, 8, 6};

    TreeNode *root = Solution().reConstructBinaryTree(pre_oredr, in_order);
    post_order_print(root);
}