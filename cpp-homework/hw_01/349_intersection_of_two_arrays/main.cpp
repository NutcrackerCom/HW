/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.


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
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::set<int> s_arr1(nums1.begin(), nums1.end());
        std::set<int> s_arr2(nums2.begin(), nums2.end());
        std::vector<int> arr;
        for(auto x: s_arr1)
        {
            if (s_arr2.count(x) > 0) 
            {
                arr.push_back(x);
            }
        }
        return arr;
    }
};

int main()
{
    Solution S;
    std::vector<int> arr1 = {1,2,2,1};
    std::vector<int> arr2 = {2,2};
    
    std::cout << S.intersection(arr1, arr2);
}