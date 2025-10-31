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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* current = head;
        ListNode* prev = nullptr;

        int len = get_len(head);
        for(int i=0; i<k%len; i++)
        {
            while (current!= nullptr)
            {
                if(current->next == nullptr && prev != nullptr)
                {
                    current->next = head;
                    prev->next = nullptr;
                    head = current;
                    break;
                }
                prev = current;
                current = current->next;
            }
            print(head);
        }
        return head;
    }

    int get_len(ListNode* head)
    {
        int len=0;
        ListNode* current = head;
        while (current!=nullptr)
        {
            current=current->next;
            len++;
        }
        return len;
        
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
    ListNode a5 = {5, nullptr};
    ListNode a6 = {4, &a5};
    ListNode a7 = {3, &a6};
    ListNode a8 = {2, &a7};
    ListNode a9 = {1, &a8};
    Solution s;
    s.rotateRight(&a9, 5);
}