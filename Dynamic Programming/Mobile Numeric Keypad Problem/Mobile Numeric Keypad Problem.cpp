/* Given the mobile numeric keypad. You can only press buttons that are up, left, right or down to the current button. 
You are not allowed to press bottom row corner buttons (i.e. * and # ).

                         '1','2','3'
                         '4','5','6'
                         '7','8','9'
                         '*','0','#'

Given a number N, find out the number of possible numbers of given length.

Examples:
For N=1, number of possible numbers would be 10 (0, 1, 2, 3, …., 9)
For N=2, number of possible numbers would be 36
Possible numbers: 00,08 11,12,14 22,21,23,25 and so on.
*/

#include <iostream>
#include <vector>

int getCount(int n)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(10));

    std::vector<std::vector<int>> paths = {
        {0,8},
        {1,2,4},
        {2,1,5,3},
        {3,2,6},
        {4,1,5,7},
        {5,2,4,6,8},
        {6,3,5,9},
        {7,4,8},
        {8,5,7,9,0},
        {9,6,8}
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (i == 1)
                dp[i][j] = 1;
            else
            {
                // ith press for jth key --> i-1 th  press should be of keys in paths[j]
                for (int prev : paths[j])
                {
                    dp[i][j] += dp[i - 1][prev];
                }
            }
        }
    }
    int result = 0;
    for (int j = 0; j <= 9; j++)
        result += dp[n][j];
    return result;
}

int main()
{
    std::cout << "Count for numbers of length 1: "  << getCount(1);
    std::cout << "\nCount for numbers of length 2: "  << getCount(2);
    std::cout << "\nCount for numbers of length 3: "  << getCount(3);
    std::cout << "\nCount for numbers of length 4: "  << getCount(4);
    std::cout << "\nCount for numbers of length 5: "  << getCount(5);

    return 0;
}


