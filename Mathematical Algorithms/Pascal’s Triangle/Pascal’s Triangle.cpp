/* Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n as input and 
prints first n lines of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.
 

1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
*/

#include <iostream>
#include <vector>

// Method 1: Time complexity : O(n^3), Space: O(1)
/*
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

void printPascal(int n)
{
    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <= line; i++)
            std::cout << " " << binomialCoeff(line, i);
        std::cout << "\n";
    }
} */

// Method 2: Time complexity : O(n^2), Space: O(n^2)
/*
void printPascal(int n)
{
    std::vector<std::vector<int>> pascal(n, std::vector<int>(n));

    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            // First and last values in every row are 1
            if (i == line || i == 0)
                pascal[line][i] = 1;
            // Other values are sum of values just above and left of above
            else
                pascal[line][i] = pascal[line - 1][i - 1] + pascal[line - 1][i];
            std::cout << pascal[line][i] << " ";
        }
        std::cout << "\n";
    }
} */

// Method 3: Time complexity : O(n^2), Space: O(1)
void printPascal(int n)
{
    for (int line = 1; line <= n; line++)
    {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++)
        {
            // The first value in a line is always 1
            std::cout << C << " ";
            C = C * (line - i) / i;
        }
        std::cout << "\n";
    }
}

int main()
{
    int n = 7;
    printPascal(n);
    return 0;
}
