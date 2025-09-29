/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, 
and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

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
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string A;
        std::string B;
        for(auto s: word1)
        {
            A+=s;
        }
        for(auto s: word2)
        {
            B+=s;
        }
        return A == B;
    }
};

int main()
{
    Solution S;
    std::vector<std::string> arr1 = {"a", "cb"};
    std::vector<std::string> arr2 = {"ab", "c"};
    std::cout << S.arrayStringsAreEqual(arr1, arr2);
}