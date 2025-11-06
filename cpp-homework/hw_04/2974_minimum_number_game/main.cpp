//https://leetcode.com/problems/minimum-number-game/description/
/*
You are given a 0-indexed integer array nums of even length and there is also an empty array arr. 
Alice and Bob decided to play a game where in every round Alice and Bob will do one move. 
The rules of the game are as follows:

    Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
    Now, first Bob will append the removed element in the array arr, and then Alice does the same.
    The game continues until nums becomes empty.

Return the resulting array arr.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int> res;
        multiset<int> s(nums.begin(), nums.end());
        int temp;
        for(auto it=s.begin(); it!= s.end(); it++)
        {
            temp = *it;
            it++;
            res.push_back(*it);
            res.push_back(temp);
        }
        return res;

    }
};