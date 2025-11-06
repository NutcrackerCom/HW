#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size()<2) return 0;
        int max=0, max_next=0;
        for(int i: nums)
        {
            if(i>=max)
            {
                max_next = max;
                max=i;
                continue;
            }
            if(i>max_next) max_next = i;

        }
        int res = (max-1) * (max_next - 1);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> t = {1,5,4,5};
    cout << s.maxProduct(t);
}