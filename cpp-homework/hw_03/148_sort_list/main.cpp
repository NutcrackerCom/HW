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
    ListNode* sortList(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* prev = nullptr;
        bool flag = true;
        while (flag)
        {
            prev = nullptr;
            flag = false;
            while(current!=nullptr && current->next!=nullptr)
            {
                next = current->next;

                if(current->val < current->next->val)
                {
                    flag = true;
                    current->next = next->next;
                    next->next = current;
                    if(prev == nullptr) head = current;
                    prev = current;
                }
            }
        }
        

        
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