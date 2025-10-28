//https://leetcode.com/problems/merge-two-sorted-lists/description/
/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode *head = list1->val<=list2->val ? list1:list2;
        ListNode *temp = head;

        if(list1->val<=list2->val) list1=list1->next;
        else list2=list2->next;

        while (list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {         
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr) temp->next=list1;
        if(list2!=nullptr) temp->next=list2;
        
        return head;
    }
};

int main()
{
    ListNode a = {3};
    ListNode b = {2, &a};
    ListNode list1 = {1, &b};

    ListNode a1 = {3};
    ListNode b1 = {2, &a1};
    ListNode list2 = {1, &b1};
    
    Solution s;
    s.mergeTwoLists(&list1, &list2);
}