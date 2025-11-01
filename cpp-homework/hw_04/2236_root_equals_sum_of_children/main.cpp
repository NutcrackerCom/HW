//https://leetcode.com/problems/root-equals-sum-of-children/description/
/*
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.
*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkTree(TreeNode* root) 
    {
        return (root->right->val + root->left->val == root->val);
    }
};

int main()
{
    TreeNode l_node(3);
    TreeNode r_node(6);
    TreeNode head_node(10, &l_node, &r_node);
    Solution s;
    std::cout << s.checkTree(&head_node);
}