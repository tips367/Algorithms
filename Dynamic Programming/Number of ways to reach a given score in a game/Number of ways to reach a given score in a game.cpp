/* Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, 
find number of ways to reach the given score.

Examples: 
 
Input: n = 20
Output: 4
There are following 4 ways to reach 20
(10, 10)
(5, 5, 10)
(5, 5, 5, 5)
(3, 3, 3, 3, 3, 5)

Input: n = 13
Output: 2
There are following 2 ways to reach 13
(3, 5, 5)
(3, 10)
*/

#include <iostream>

int numWays(int n)
{
    int* dp = new int[n+1];

    // Base case
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        dp[i] = 0;

    // One by one consider given 3 moves and update the dp[] values after
    // the index greater than or equal to the value of the picked move
    for (int i = 3; i <= n; i++)
        dp[i] += dp[i - 3];

    for (int i = 5; i <= n; i++)
        dp[i] += dp[i - 5];

    for (int i = 10; i <= n; i++)
        dp[i] += dp[i - 10];

    return dp[n];
}

int main(void)
{
    std::cout << "Count for 20 is " << numWays(20) << std::endl;
    std::cout << "Count for 13 is " << numWays(13) << std::endl;
    return 0;
}


