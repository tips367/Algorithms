/* Imagine you have a special keyboard with the following keys: 
* 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. 

If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum 
numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the  output is M 
(No. of As that you can produce).

Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
*/

#include <iostream>
#include <vector>

// Method 1: Recursive
/*
int optimalKeys(int N)
{
	if (N <= 6)
		return N;

    int max = 0;

	for (int i = N - 3; i >= 1; i--)
	{
        int curr = (N - i - 1) * optimalKeys(i);
		max = std::max(max, curr);
	}
	return max;
} */

// Method 2: Using dynamic programming
int optimalKeys(int N)
{
    if (N <= 6)
        return N;

    std::vector<int> dp(N + 1, 0);
    for (int i = 1; i <= 6; i++)
        dp[i] = i;

    for (int i = 7; i <= N; i++)
    {
        for (int j = i - 3; j >= 1; j--)
        {
            int curr = dp[j] * (i - j - 1);
            dp[i] = std::max(dp[i], curr);
        }
    }
    return dp[N];
}

int main()
{
    for (int N = 1; N <= 20; N++)
        std::cout << "Maximum Number of A's with " << N << " keystrokes is " << optimalKeys(N) << std::endl;
}


