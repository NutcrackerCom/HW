#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> avg;
        sort(nums.begin(), nums.end());
        for(size_t i=0; i<nums.size()/2; i++)
        {
            avg.push_back((static_cast<double>(nums[i]+nums[nums.size()-1-i])/2));
            cout << nums[i] << " " << nums[nums.size()-1-i] << " " << avg[i] << " avg\n";
        }
        sort(avg.begin(), avg.end());
        for(auto i: avg)
        {
            cout << i << " ";
        }
        if(avg.size()) return avg[0];
        return 0;
    }
};

int main()
{
    vector<int> nums = {7,8,3,4,15,13,4,1};
    Solution s;
    s.minimumAverage(nums);
}