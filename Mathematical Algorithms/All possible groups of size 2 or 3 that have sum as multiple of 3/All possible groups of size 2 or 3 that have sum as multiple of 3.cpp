/* Given an unsorted integer (positive values only) array of size ‘n’, we can form a group of two or three, 
the group should be such that the sum of all elements in that group is a multiple of 3. 
Count all possible number of groups that can be generated in this way. 
Examples: 
 

Input: arr[] = {3, 6, 7, 2, 9}
Output: 8
// Groups are {3,6}, {3,9}, {9,6}, {7,2}, {3,6,9},
//            {3,7,2}, {7,2,6}, {7,2,9}


Input: arr[] = {2, 1, 3, 4}
Output: 4
// Groups are {2,1}, {2,4}, {2,1,3}, {2,4,3}
*/

#include <iostream>

int findgroups(int arr[], int n)
{
    // Create an array C[3] to store counts of elements with remainder 0, 1 and 2.
    // c[i] would store count of elements with remainder i
    int c[3] = { 0 };

    int result = 0;

    // Count elements with remainder 0, 1 and 2
    for (int i = 0; i < n; i++)
        c[arr[i] % 3]++;

    // Case 3.a: Count groups of size 2 from 0 remainder elements
    result += ((c[0] * (c[0] - 1)) >> 1);

    // Case 3.b: Count groups of size 2 with one element with 1 remainder and other with 2 remainder
    result += c[1] * c[2];

    // Case 4.a: Count groups of size 3 with all 0 remainder elements
    result += (c[0] * (c[0] - 1) * (c[0] - 2)) / 6;

    // Case 4.b: Count groups of size 3 with all 1 remainder elements
    result += (c[1] * (c[1] - 1) * (c[1] - 2)) / 6;

    // Case 4.c: Count groups of size 3 with all 2 remainder elements
    result += ((c[2] * (c[2] - 1) * (c[2] - 2)) / 6);

    // Case 4.c: Count groups of size 3 with different remainders
    result += c[0] * c[1] * c[2];

    return result;
}

int main()
{
    int arr[] = { 3, 6, 7, 2, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Required number of groups are " << findgroups(arr, n) << std::endl;
    return 0;
}
