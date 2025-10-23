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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head1 = list1;
        ListNode* head2 = list2;
        std::vector<int> vec;

        while (head1!=nullptr || head2!=nullptr)
        {   
            if(head1!=nullptr)
            {
                vec.push_back(head1->val);
                head1 = head1->next;
            }
            if(head2!=nullptr)
            {
                vec.push_back(head2->val);
                std::cout << "a";
                head2 = head2->next;
            }
        }
        std::sort(vec.begin(), vec.end());
        ListNode *head = new ListNode();
        ListNode *curr = head;
        for(auto i: vec)
        {
            curr->next= new ListNode(i);
            curr = curr->next;
        }

        curr = head->next;
        while (curr!=nullptr)
        {
            std::cout << curr->val;
            curr=curr->next;
        }
        
        return head->next;
    }
};

int main()
{
    ListNode a = 1;
    ListNode b = {2, &a};
    ListNode c = {3, &b};
    ListNode a1 = 4;
    ListNode b1 = {5, &a1};
    ListNode c1 = {6, &b1};
    Solution s;
    s.mergeTwoLists(&c, nullptr);
}