/*
Given an integer array nums of length n, you want to create an array ans of length 2n 
where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.
*/

#include <iostream>
#include <vector>
#include <map>
#define NF -1

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
    std::vector<int> getConcatenation(std::vector<int>& nums) 
    {
        std::vector<int> cp = nums;

        for(auto i: cp)
        {
            nums.push_back(i);
        }
        return nums;
        
    }
};

int main()
{
    Solution S;
    std::vector<int> arr = {1,2,1};
    S.getConcatenation(arr);
    std::cout << arr;
}