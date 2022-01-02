/* Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. 
The expected time complexity is O(n) and O(1) extra space. 

Examples:

Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
In the given array all element appear three times except 2 which appears once.

Input: arr[] = {10, 20, 10, 30, 10, 30, 30}
Output: 20
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Method 1: Using Hashing...Time : O(n), Space : O(n)
/*
int singleNumber(std::vector<int>& nums) 
{
    std::unordered_map<int, int> hashmap;
    for (int num : nums)
    {
        hashmap[num]++;
    }
    for (int num : nums)
    {
        if (hashmap[num] == 1)
            return num;
    }
    return 0;
} */

// Method 2: Using Sorting...Time : O(n log n)
/*
int singleNumber(std::vector<int>& nums) 
{
    int n = nums.size();
    if (n < 3)
        return nums[0];

    std::sort(nums.begin(), nums.end());
    if (nums[0] != nums[1])
        return nums[0];
    int i = 1;
    while (i < n)
    {
        if (nums[i] != nums[i - 1])
            return nums[i - 1];
        i += 3;
    }
    return nums[n - 1];
} */

// Method 3: Bitwise...Time : O(n), Space: O(1)
/*
int singleNumber(std::vector<int>& nums) 
{
    int n = nums.size();
    unsigned int ans = 0, shift = 1;
    for (int i = 0; i < 32; ++i)
    {
        int count = 0;
        for (auto ele : nums)
        {
            if (ele & shift)
                count += 1;
        }
        if (count % 3 != 0)
            ans += shift;
        shift *= 2;

    }
    return ans;
} */

// Method 4: Another Bitwise...Time : O(n), Space: O(1)
int singleNumber(std::vector<int>& nums)
{
    int ones = 0;
    int twos = 0;
    for (auto ele : nums)
    {
        ones = (ones ^ ele) & (~twos);
        twos = (twos ^ ele) & (~ones);
    }
    return ones;
}

int main()
{
    std::vector<int> nums = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7 };
    std::cout << singleNumber(nums);
    return 0;
}

