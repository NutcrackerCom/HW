/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

*/

#include <iostream>
#include <vector>
#include <map>
#define NF -1

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    std::cout << "[";
    for(auto i: arr)
    {
        if(i == arr.back()) std::cout << i << "]";

        else std::cout << i << ",";
    }
    std::cout << std::endl;
    return os;
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {

        int diff;
        std::map<int, int> map_i_dif;
        for(int i=0; i<nums.size(); i++)
        {
            diff = target-nums[i];
            if(map_i_dif.find(diff) != map_i_dif.end())
            {
                return {map_i_dif[diff], i};
            }
            map_i_dif[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution S;
    std::vector<int> arr = {2,7,11,15};
    int target = 9;
    
    std::cout << S.twoSum(arr, target);
}