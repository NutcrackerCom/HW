//https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/submissions/1817534536/?envType=daily-question&envId=2025-11-01
/*
You are given an array of integers nums and the head of a linked list. 
Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) 
    {
    std::unordered_set<int> set_nums(nums.begin(), nums.end());
    if(head == nullptr) return head;

    ListNode* current = head;
    ListNode* next = current->next;
    ListNode* prev = nullptr;
    while(current!=nullptr)
    {
        if(set_nums.count(current->val))
        {
        if(prev == nullptr)
            { 
                head = next;
            }
            else
            {
                prev->next = next;
            }
        }
        else prev = current;
        current = current->next;
        if(current) next = current->next;
            
    }
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
    //[1,2,1,2,1,2]
    ListNode a1 = 6;
    ListNode a2 = {5, &a1};
    ListNode a3 = {4, &a2};
    ListNode a4 = {4, &a3};
    ListNode a5 = {1, &a4};
    ListNode a6 = {2, &a5};
    ListNode c = {7, &a6};
    std::vector<int> d = {4,9};
    Solution s;
    s.modifiedList(d, &a4);
}