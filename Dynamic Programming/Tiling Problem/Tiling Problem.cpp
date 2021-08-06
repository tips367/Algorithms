/* Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles. 
A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

Examples: 

Input: n = 4

Output: 5

*/

#include <iostream>

int getNoOfWays(int n)
{
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    std::cout << getNoOfWays(2) << std::endl;
    std::cout << getNoOfWays(3) << std::endl;
    std::cout << getNoOfWays(4) << std::endl;
}


