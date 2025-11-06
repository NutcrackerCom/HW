//https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/
/*
In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. 
Each number was supposed to appear exactly once in the list, however, 
two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. 
Return an array of size two containing the two numbers (in any order), 
so peace can return to Digitville.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) 
    {
        std::vector<int> scout;
        std::sort(nums.begin(), nums.end());
        for(size_t i=0; i<nums.size(); i++)
        {
            if(nums[i] == nums[i+1])
            {
                scout.push_back(nums[i]);
                if(scout.size() == 2) return scout;
            }
        }
        return scout;
    }
};