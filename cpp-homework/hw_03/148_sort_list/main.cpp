// Bubble Sort 

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
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        bool sorted = false;
        while (!sorted)
        {
            current = head;
            prev = nullptr;
            sorted = true;
            while(current!=nullptr && current->next!=nullptr)
            {
                next = current->next;

                if(current->val > current->next->val)
                {
                    sorted = false;

                    current->next = next->next;
                    next->next = current;

                    if(prev == nullptr) head = next;
                    else prev->next = next;

                    prev = next;
                }
                else
                {
                    prev = current;
                    current = current->next;
                }
                print(head);
            }
            std::cout<< sorted << std::endl;
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
    //[-1,5,3,4,0]
    ListNode a1 = 0;
    ListNode a2 = {4, &a1};
    ListNode a3 = {3, &a2};
    ListNode a4 = {5, &a3};
    ListNode a5 = {-1, &a4};
    ListNode a6 = {6, &a5};
    ListNode c = {7, &a6};
    Solution s;
    s.sortList(&a5);
}