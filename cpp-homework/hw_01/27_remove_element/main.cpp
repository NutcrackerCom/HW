/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, 
you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.

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
    int removeElement(std::vector<int>& nums, int val) {
        int step_del=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[step_del] = nums[i];
                step_del++;
            }
        }
        return step_del;
    }
};

int main()
{
    Solution S;
    std::vector<int> arr = {3,2,2,3};
    int target = 3;
    
    std::cout << S.removeElement(arr, target) << " arr = " << arr;
}