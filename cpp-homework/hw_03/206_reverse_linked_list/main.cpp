//https://leetcode.com/problems/reverse-linked-list/description/
/*
Given the head of a singly linked list, reverse the list, 
and return the reversed list.
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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr!=nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }



    void print(ListNode* head)
    {
        ListNode* buff = head;
        while (buff!=nullptr)
        {
            std::cout << buff->val;
            buff=buff->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    ListNode a = 1;
    ListNode b = {2, &a};
    ListNode c = {3, &b};
    Solution s;
    //s.print(&c);
    ListNode* p = s.reverseList(&c);
    s.print(p);

}