//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

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
        
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* curr = head->next;
        ListNode* buff=head;
        while (curr!=nullptr)
        {
            std::cout<< curr->val<<std::endl;
            if(head->val!=curr->val)
            {
                head->next=curr;
                head=head->next;
                std::cout<<"added "<< curr->val<<std::endl;
            }
            else head->next=nullptr;
            curr=curr->next;
        }      
        return buff;
    }
};

int main()
{
    ListNode a = 1;
    ListNode b = {1, &a};
    ListNode c = {3, &b};
    ListNode d = {3, &c};
    ListNode e = {4, &d};
    Solution s;
    s.deleteDuplicates(nullptr);
    //s.mergeTwoLists(&c, nullptr);
}