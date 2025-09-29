/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/

#include <iostream>
#include <vector>
#include <map>

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
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> buf = nums;
    for(int i=0; i<n; i++)
    {
        nums[2*i] = buf[i];
        nums[nums.size()-1-2*i] = buf[nums.size()-1-i];
    }
    return nums;
    }
};

int main()
{
    Solution S;
    std::vector<int> arr = {2,5,1,3,4,7};
    S.shuffle(arr, 3);
    std::cout << arr;
}