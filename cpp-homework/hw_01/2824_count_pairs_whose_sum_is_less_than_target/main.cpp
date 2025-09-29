/*
Given a 0-indexed integer array nums of length n and an integer target, 
return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target. 
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

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
private:
    bool static comp(int a, int b) 
    {
        return a < b;
    }
public:
    int countPairs(std::vector<int>& nums, int target) {
        int count=0;
        int i=0, j=nums.size()-1;
        std::sort(nums.begin(), nums.end(), comp);
        while (i!=j)
        {
            if(nums[i]+nums[j] < target) 
            {
                count += j-i;
                i++;
            } 
            else j--;
        }
        
        return count;
    }
};

int main()
{
    Solution S;
    std::vector<int> arr = {-1,1,2,3,1};
    std::cout << arr;
    int target = 2;
    std::cout << S.countPairs(arr, target);
}

/*

diff
count  
[-6,2,5,-2,-7,-1,3] target = -2
[ 0. 1. 2. 3. 4. 5. 6]
[-7,-6,-2,-1, 2, 3, 5]
-7 5 x -7 3 -> 5
-6 3 -> 4
-2 2 x -2 -1 -> 1

*/