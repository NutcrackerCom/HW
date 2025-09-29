/*
Given a 0-indexed integer array nums, return the smallest index i of nums such that 
i mod 10 == nums[i], or -1 if such index does not exist.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    std::cout << "[";
    auto it = arr.begin();
    
    while(it != arr.end())
    {
        std::cout << *it; 
        it++;
        if(it != arr.end()) std::cout << ","; 
    }
    std::cout << "]";
    std::cout << std::endl;
    return os;
}

class Solution {
public:
    int smallestEqual(std::vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            if(i%10 == nums[i]) return i;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    std::vector<int> arr1 = {0,1,2};

    
    std::cout << S.smallestEqual(arr1);
}