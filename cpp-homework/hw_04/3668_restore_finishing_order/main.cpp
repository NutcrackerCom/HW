//https://leetcode.com/problems/restore-finishing-order/
/*
You are given an integer array order of length n and an integer array friends.
order contains every integer from 1 to n exactly once, representing the IDs of the participants of a race in their finishing order.
friends contains the IDs of your friends in the race sorted in strictly increasing order. 
Each ID in friends is guaranteed to appear in the order array.
Return an array containing your friends' IDs in their finishing order.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> set_friends(friends.begin(), friends.end());
        vector<int> res;
        for(int i: order)
        {
            if(set_friends.count(i)) res.push_back(i);
        }
        return res;
    }
};

int main()
{
    vector<int> order = {3,1,2,5,4};
    vector<int> friends = {1,3,4};
    Solution s;
}