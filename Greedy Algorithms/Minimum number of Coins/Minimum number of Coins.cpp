/* Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, 
i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins
and/or notes needed to make the change?

Examples:

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void findMin(std::vector<int>& deno, int V)
{
    std::sort(deno.begin(), deno.end());
    std::vector<int> ans;

    int n = size(deno);

    for (int i = n - 1; i >= 0; i--) 
    {
        while (V >= deno[i]) 
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    for (auto i: ans)
        std::cout << i << " ";
}

int main()
{
    std::vector<int> deno = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int value = 93;
    std::cout << "Following is minimal" << " number of change for " << value << ": ";
    findMin(deno, value);
    return 0;
}
