//https://leetcode.com/problems/swap-nodes-in-pairs/description/
/*
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* newHead = head->next;
    
    while (curr && curr->next) {
        ListNode* first = curr;
        ListNode* second = curr->next;
        ListNode* nextPair = second->next;
        
        second->next = first;
        first->next = nextPair;
        if (prev) {
            prev->next = second;
        }
        prev = first;
        curr = nextPair;
    }
    print(newHead);
    return newHead;
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
    ListNode a1 = 1;
    ListNode a2 = {2, &a1};
    ListNode a3 = {3, &a2};
    ListNode a4 = {4, &a3};
    ListNode a5 = {5, &a4};
    ListNode a6 = {6, &a5};
    ListNode c = {7, &a6};
    Solution s;
    s.swapPairs(&c);
}