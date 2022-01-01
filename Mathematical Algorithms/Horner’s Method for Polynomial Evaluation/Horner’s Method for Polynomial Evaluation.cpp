/* Given a polynomial of the form cnxn + cn-1xn-1 + cn-2xn-2 + … + c1x + c0 and a value of x, find the value of polynomial for a given value of x.
Here cn, cn-1, .. are integers (may be negative) and n is a positive integer.
Input is in the form of an array say poly[] where poly[0] represents coefficient for xn and poly[1] represents coefficient for xn-1 and so on.
Examples: 

// Evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
Input: poly[] = {2, -6, 2, -1}, x = 3
Output: 5
*/

#include <iostream>

int horner(int poly[], int n, int x)
{
    int result = poly[0];

    for (int i = 1; i < n; i++)
        result = result * x + poly[i];

    return result;
}

int main()
{
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    int poly[] = { 2, -6, 2, -1 };
    int x = 3;
    int n = sizeof(poly) / sizeof(poly[0]);
    std::cout << "Value of polynomial is " << horner(poly, n, x);
    return 0;
}

