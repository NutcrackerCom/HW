//https://leetcode.com/problems/invert-binary-tree/submissions/1821425065/
/*
Given the root of a binary tree, invert the tree, and return its root.
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head = root;
        if(head==nullptr) return head;
        if(head->left==nullptr && head->right==nullptr) return head;
        invertTree(head->left);
        invertTree(head->right);

        TreeNode* temp = head->left;
        head->left = head->right;
        head->right = temp;
        return root;
    }

    void print(TreeNode* root)
    {
        TreeNode* head = root;
        if(head==nullptr) return;
        print(head->left);
        print(head->right);

        std::cout << head->val << " ";
    }
};

int main()
{
    TreeNode r_node3(7);
    TreeNode l_node3(6);
    TreeNode r_node2(5);
    TreeNode l_node2(4);
    TreeNode l_node1(2,&l_node2, &r_node2);
    TreeNode r_node1(3, &l_node3, &r_node3);
    TreeNode head_node(1, &l_node1, &r_node1);
    Solution s;
    s.print(&head_node);
    std::cout << "\n";
    s.invertTree(&head_node);
    s.print(&head_node);
}