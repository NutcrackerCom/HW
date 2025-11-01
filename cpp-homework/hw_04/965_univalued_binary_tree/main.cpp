#include <iostream>
#include <unordered_set>

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
    bool isUnivalTree(TreeNode* root) 
    {
        TreeNode* head = root;
        if(head == nullptr) return res;
        isUnivalTree(head->left);
        isUnivalTree(head->right);
        s.insert(head->val);
        std::cout << s.size();
        if(s.size()>1) res=false;
        return res;
    }
private:
    bool res = true;
    std::unordered_set<int> s;
};

int main()
{
    TreeNode r_node2(1);
    TreeNode l_node2(1);
    TreeNode l_node1(1,&l_node2, &r_node2);
    TreeNode r_node1(5);
    TreeNode head_node(1, &l_node1, &r_node1);
    Solution s;
    std::cout << s.isUnivalTree(&head_node);
}