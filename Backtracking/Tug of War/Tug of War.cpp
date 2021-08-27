/* Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of 
two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, 
then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

For example, let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the size of set is 10. 
Output for this set should be {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. 
Both output subsets are of size 5 and sum of elements in both subsets is same (148 and 148). 
*/

#include <iostream>
#include <vector>

using namespace std;

void tugOfWarUtil(vector<int> nums, bool* currentElements, bool* solutionArr, int numSelectedItems, 
    int totalSum, int currentSum, int& minDiff, int currentPos)
{
    int n = nums.size();
    // checks whether the it is going out of bound
    if (currentPos == n)
        return;

    // checks that the numbers of elements left in array are not less than the
    // number of elements required to form the solution
    if ((n / 2 - numSelectedItems) > (n - currentPos))
        return;

    // consider the case when current element is not included in the solution
    tugOfWarUtil(nums, currentElements, solutionArr, numSelectedItems, totalSum, currentSum, minDiff, currentPos + 1);

    // add current element to solution
    currentElements[currentPos] = true;
    numSelectedItems++;
    currentSum = currentSum + nums[currentPos];

    // checks if a solution is formed
    if (numSelectedItems == n / 2)
    {
        // check if soultion is better than previous one
        if (abs(totalSum / 2 - currentSum) < minDiff)
        {
            minDiff = abs(totalSum / 2 - currentSum);
            for (int i = 0; i < n; i++)
                solutionArr[i] = currentElements[i];
        }
    }
    else
    {
        // consider the case when current element is included in the solution
        tugOfWarUtil(nums, currentElements, solutionArr, numSelectedItems, totalSum, currentSum, minDiff, currentPos + 1);
    }

    currentElements[currentPos] = false;
}

void tugOfWar(vector<int>& nums)
{
    int n = nums.size();

    // the boolean array that contains the inclusion and exclusion of an element in current set
    bool* currentElements = new bool[n];

    bool* solutionArr = new bool[n];

    int minDiff = INT_MAX;

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
        currentElements[i] = solutionArr[i] = false;
    }

    int currentSum = 0, currentPos = 0, numSelectedItems = 0;
    tugOfWarUtil(nums, currentElements, solutionArr, numSelectedItems, totalSum, currentSum, minDiff, currentPos);

    cout << "The first subset is: ";
    for (int i = 0; i < n; i++)
    {
        if (solutionArr[i] == true)
            cout << nums[i] << " ";
    }
    cout << "\nThe second subset is: ";
    for (int i = 0; i < n; i++)
    {
        if (solutionArr[i] == false)
            cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
    tugOfWar(nums);
    return 0;
}
