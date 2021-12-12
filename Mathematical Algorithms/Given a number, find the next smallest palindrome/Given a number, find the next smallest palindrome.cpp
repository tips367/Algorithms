/* Given a number, find the next smallest palindrome larger than this number. For example, if the input number is “2 3 5 4 5”, the output 
should be “2 3 6 3 2”. And if the input number is “9 9 9”, the output should be “1 0 0 1”. 
The input is assumed to be an array. Every entry in array represents a digit in input number. 
Let the array be ‘num[]’ and size of array be ‘n’
*/


/* There can be three different types of inputs that need to be handled separately. 
1) The input number is palindrome and has all 9s. For example “9 9 9”. Output should be “1 0 0 1” 
2) The input number is not palindrome. For example “1 2 3 4”. Output should be “1 3 3 1” 
3) The input number is palindrome and doesn’t have all 9s. For example “1 2 2 1”. Output should be “1 3 3 1”.
*/

#include <iostream>

int AreAll9s(int num[], int n)
{
    for (int i = 0; i < n; ++i)
        if (num[i] != 9)
            return 0;
    return 1;
}

void handleLeftSmaller(int num[], int n, int mid)
{
    int carry = 1;
    int i = mid - 1;
    int j;

    // If there are odd digits, then increment the middle digit and store the carry
    if (n % 2 == 1)
    {
        num[mid] += carry;
        carry = num[mid] / 10;
        num[mid] %= 10;
        j = mid + 1;
    }
    else
        j = mid;

    // Add 1 to the rightmost digit of the left side, propagate the carry towards
    // MSB digit and simultaneously copying mirror of the left side to the right side.
    while (i >= 0)
    {
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;

        // Copy mirror to right
        num[j++] = num[i--];
    }
}

void generateNextPalindromeUtil(int num[], int n)
{
    // Find the index of mid digit
    int mid = n / 2;

    // End of left side is always 'mid -1'
    int i = mid - 1;

    // Beginning of right side depends if n is odd or even
    int j = (n % 2) ? mid + 1 : mid;

    // Initially, ignore the middle same digits
    while (i >= 0 && num[i] == num[j])
        i--, j++;

    // A bool variable to check if copy of left side to right is sufficient or not
    bool leftsmaller = false;

    // Find if the middle digit(s) need to be incremented or not (or copying left side is not sufficient)
    if (i < 0 || num[i] < num[j])
        leftsmaller = true;

    // Copy the mirror of left to tight
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }

    if (leftsmaller)
        handleLeftSmaller(num, n, mid);
}

void generateNextPalindrome(int num[], int n)
{
    std::cout << "Next palindrome is:";

    // Input type 1: All the digits are 9, simply o/p 1
    // followed by n-1 0's followed by 1.
    if (AreAll9s(num, n))
    {
        printf("1 ");
        for (int i = 1; i < n; i++)
            printf("0 ");
        printf("1");
    }
    // Input type 2 and 3
    else
    {
        generateNextPalindromeUtil(num, n);
        for (int i = 0; i < n; i++)
            std::cout << num[i] << " ";
    }
}

int main()
{
    int num[] = { 9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2 };

    int n = sizeof(num) / sizeof(num[0]);

    generateNextPalindrome(num, n);

    return 0;
}
