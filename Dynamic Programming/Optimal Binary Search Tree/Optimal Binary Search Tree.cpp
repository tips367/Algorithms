/* Given a sorted array key [0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, 
where freq[i] is the number of searches for keys[i]. Construct a binary search tree of all keys such that 
the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is the level of that node multiplied by its frequency. 
The level of the root is 1.

Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
There can be following possible BSTs
    10                12                 20         10              20
      \             /    \              /             \            /
      12          10     20           12               20         10
        \                            /                 /           \
         20                        10                12             12
     I               II             III             IV             V

Among all possible BSTs, cost of the fifth BST is minimum.
Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142
*/

#include <iostream>
#include <vector>

// Time complexity : O(n^3)
int costOptimalBST(int keys[], int freq[], int n)
{
    // cost[i][j] = Optimal cost of binary search tree that can be formed from keys[i] to keys[j].
    std::vector<std::vector<int>> cost(n, std::vector<int>(n));

    int* prefixSumArray = new int[n];
    prefixSumArray[0] = freq[0];

    for (int i = 1; i < n; i++)
        prefixSumArray[i] = prefixSumArray[i - 1] + freq[i];

    // For a single key, cost is equal to frequency of the key as it will be the root
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // With two keys there are two possible arrangements, we take minimum cost out of those arrangements
    for (int i = 0; i < n - 1; i++)
    {
        cost[i][i + 1] = std::min(freq[i] + 2 * freq[i + 1], freq[i + 1] + 2 * freq[i]);
    }

    // Check for lengths greater than 2
    for (int currLen = 3; currLen <= n; currLen++)
    {
        // Fix the starting index
        for (int i = 0; i < n - currLen + 1; i++)
        {
            int j = i + currLen - 1;
            cost[i][j] = INT_MAX;
            int fs = prefixSumArray[j] - (i == 0 ? 0 : prefixSumArray[i - 1]);

            // Try making all keys in interval keys[i..j] as root
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : cost[i][k - 1];
                int right = k == j ? 0 : cost[k + 1][j];
                cost[i][j] = std::min(cost[i][j], left + right + fs);
            }    
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int keys[] = { 10, 12, 20 };
    int freq[] = { 34, 8, 50 };
    int n = sizeof(keys) / sizeof(keys[0]);
    std::cout << "Cost of Optimal BST is " << costOptimalBST(keys, freq, n);
    return 0;
}

