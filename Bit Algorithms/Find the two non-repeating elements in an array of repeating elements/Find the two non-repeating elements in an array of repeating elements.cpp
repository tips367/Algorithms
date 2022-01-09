/* Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
*/

#include <iostream>
#include <vector>

std::vector<int> singleNumber(std::vector<int>& nums) 
{
    std::vector<int> res{ 0,0 };
    long long x_xor_y = 0;
    for (int num : nums)
    {
        x_xor_y ^= num;
    }

    long long mask = x_xor_y & -x_xor_y;
    for (int num : nums)
    {
        if (mask & num)
            res[0] ^= num;
        else
            res[1] ^= num;
    }

    return res;
}

int main()
{
    std::vector<int> nums = { 2, 3, 7, 9, 11, 2, 3, 11 };
    std::vector<int> res = singleNumber(nums);
    std::cout << "The non-repeating elements are " << res[0] << " and " << res[1];
}

