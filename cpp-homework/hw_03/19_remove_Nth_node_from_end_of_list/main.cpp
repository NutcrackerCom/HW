//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    //void print(ListNode* head);

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int step=0;
        ListNode* list=head;
        ListNode* buff=head;
        bool flag=false;
        while (list!=nullptr)
        {
            list=list->next;
            if(step!=n) step++;
            else
            {
                flag = true;
                if(list!= nullptr)
                {
                    buff=buff->next;
                }
            }
        }
        if(!flag && step==n)
        {
            head= head->next;
        }
        if(buff->next!=nullptr)
        {
            if(buff->next->next != nullptr)
            {
                buff->next = buff->next->next;
            }  
            else buff->next=nullptr;
        }
        else buff = nullptr;
        print(head);
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
    ListNode a1 = 1;
    ListNode a2 = {2, &a1};
    ListNode a3 = {3, &a2};
    ListNode a4 = {4, &a3};
    ListNode a5 = {5, &a4};
    ListNode a6 = {6, &a5};
    ListNode c = {7, &a6};
    Solution s;
    int i;
    std::cin >> i;
    s.removeNthFromEnd(&c, i);
}