//https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1821487683/
/*
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* head = root;
        if(head == nullptr || head->val == val) return head;
        
        if(head->val < val) return searchBST(head->right, val);
    
        return searchBST(head->left, val);
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
    /*TreeNode r_node3(7);
    TreeNode l_node3(6);
    TreeNode r_node2(5);
    TreeNode l_node2(4);
    TreeNode l_node1(2,&l_node2, &r_node2);
    TreeNode r_node1(3, &l_node3, &r_node3);
    TreeNode head_node(1, &l_node1, &r_node1);*/
    TreeNode l_node3(15);
    TreeNode r_node2(30, &l_node3, nullptr);
    TreeNode l_node1(2,nullptr, &r_node2);
    TreeNode r_node1(93);
    TreeNode head_node(62, &l_node1, &r_node1);
    Solution s;
    TreeNode* res = s.searchBST(&head_node, 15);
    s.print(res);
    //std::cout << res->val <<"\n";
}