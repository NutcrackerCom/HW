//https://leetcode.com/problems/reverse-linked-list-ii/description/
/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* prev = nullptr;
        bool sorted = false;
        int step = 1;
        if(left == right || left > right) return head;
        while (left < right)
        {
            current = head;
            sorted = true;
            prev = nullptr;
            step = 1;
            
            while (current!=nullptr && current->next != nullptr)
            {
                next = current->next;
                if((step >= left && step < right))
                {
                    sorted = false;
                    current->next = next->next;
                    next->next = current;
                    if(prev==nullptr) head = next;
                    else
                    {
                        prev->next = next;
                    }
                    prev = next;
                }
                else
                {
                    prev = current;
                    current=current->next;
                }
                step++;
            }
            right--;
            print(head);
        }
        return head;
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
    //9876543210 1 10
    //
    ListNode a1 = 9;
    ListNode a2 = {8, &a1};
    ListNode a3 = {7, &a2};
    ListNode a4 = {6, &a3};
    ListNode a5 = {5, &a4};
    ListNode a6 = {4, &a5};
    ListNode a7 = {3, &a6};
    ListNode a8 = {2, &a7};
    ListNode a9 = {1, &a8};
    ListNode a10 = {7, &a9};
    Solution s;
    s.reverseBetween(&a9, 2, 5);
}
