/* A magic square of order n is an arrangement of n^2 numbers, usually distinct integers, in a square, such that the n numbers in all rows, 
all columns, and both diagonals sum to the same constant. A magic square contains the integers from 1 to n^2. 
The constant sum in every row, column and diagonal are called the magic constant or magic sum, M. The magic constant of a normal magic 
square depends only on n and has the following value: 
M = n(n2+1)/2

For normal magic squares of order n = 3, 4, 5, ...,
the magic constants are: 15, 34, 65, 111, 175, 260, ... 

example:

Magic Square of size 3
-----------------------
  2   7   6
  9   5   1
  4   3   8
Sum in each row & each column = 3*(32+1)/2 = 15


Magic Square of size 5
----------------------
  9   3  22  16  15
  2  21  20  14   8
 25  19  13   7   1
 18  12   6   5  24
 11  10   4  23  17
Sum in each row & each column = 5*(52+1)/2 = 65
*/

#include <iostream>
#include <vector>
#include <iomanip>


/*
Three conditions hold:
1. The position of next number is calculated by decrementing row number of the previous number by 1, and incrementing the column number
of the previous number by 1. At any time, if the calculated row position becomes -1, it will wrap around to n-1. Similarly, if the 
calculated column position becomes n, it will wrap around to 0.
2. If the magic square already contains a number at the calculated position, calculated column position will be decremented by 2, 
and calculated row position will be incremented by 1.
3. If the calculated row position is -1 & calculated column position is n, the new position would be: (0, n-2).

NOTE: This approach works only for odd values of n.
*/

void generateSquare(int n)
{
    std::vector<std::vector<int>> magicSquare(n, std::vector<int>(n, 0));

    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        // 3rd condition
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }

        // 2nd condition
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;

        // 1st condition
        j++;
        i--;

    }

    std::cout << "The Magic Square for n=" << n << ":\nSum of each row or column " << n * (n * n + 1) / 2 << ":\n\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            std::cout << std::setw(4) << magicSquare[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    // Works only when n is odd
    int n = 7;
    generateSquare(n);
    return 0;
}

