//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> sort_nums(nums.begin(), nums.end());
        sort(sort_nums.begin(), sort_nums.end());
        vector<int> res;

        unordered_map<int, int> map_nums;
        for(int i=0; i<sort_nums.size(); i++)
        {
            if(!map_nums.count(sort_nums[i])) map_nums[sort_nums[i]] = i;
        }

        for(int i: nums)
        {
            res.push_back(map_nums[i]);
        }
        return res;
    }
};
