/* Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated (>= 0)
Find the maximum profit subset of jobs such that no two jobs in the subset overlap. 

Example: 

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.

We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.
*/

#include <iostream>
#include <algorithm>

// A job has start time, finish time and profit.
struct Job
{
    int start, finish, profit;
};

// A utility function that is used for sorting events according to finish time
bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int findMaxProfit(Job arr[], int n)
{
    std::sort(arr, arr + n, jobComparataor);
    int* dp = new int[n];

    dp[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i].profit;

        // Find the latest job(in sorted array) that doesn't conflict with the job[i]
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j].finish <= arr[i].start)
            {
                dp[i] = std::max(dp[i], arr[i].profit + dp[j]);
                break;
            }
        }
    }
    return *std::max_element(dp, dp + n);
}

int main()
{
    Job arr[] = { {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200} };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}

