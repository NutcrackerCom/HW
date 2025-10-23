#include <iostream>
#include <vector>
#include <algorithm>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        std::vector<int> vec;
        ListNode* curr = head;
        int buf=head->val;
        vec.push_back(buf);
        while (curr!=nullptr)
        {
            std::cout << curr->val << " val \n";
            if(buf!=curr->val)
            {
                buf=curr->val;
                vec.push_back(buf);
                std::cout << curr->val << " added \n";
            }
            curr=curr->next;
        }
        ListNode* res = new ListNode();
        curr = res;
        for(auto i: vec)
        {
            std::cout << i << " in vec \n";
            curr->next = new ListNode(i);
            curr=curr->next;
        }

        curr = res;
        while (curr!=nullptr)
        {
            std::cout << curr->val;
            curr=curr->next;
        }
        return res->next;
        
    }
};

int main()
{
    ListNode a = 1;
    ListNode b = {1, &a};
    ListNode c = {3, &b};
    ListNode a1 = 4;
    ListNode b1 = {5, &a1};
    ListNode c1 = {6, &b1};
    Solution s;
    s.deleteDuplicates(&c);
    //s.mergeTwoLists(&c, nullptr);
}