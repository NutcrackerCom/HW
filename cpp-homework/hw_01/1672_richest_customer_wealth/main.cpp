/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money 
the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum wealth.
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
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max=0;
        int sum=0;
        for(auto arr: accounts)
        {
            sum=0;
            for(auto wealth: arr)
            {
                sum+=wealth;
            }
            if(sum>max) max=sum;
        }
    return max;
    }
};

int main()
{
    Solution S;
    std::vector<std::vector<int>> arr = {{1,2,3},{1,2,3}};
    
    std::cout << S.maximumWealth(arr);
}