/* Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also 
given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if 
only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following
deadlines and profits
JobID  Deadline  Profit
  a      4        20
  b      1        10
  c      1        40
  d      1        30
Output: Following is maximum
profit sequence of jobs
        c, a


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum
profit sequence of jobs
        c, a, e
*/

#include <iostream>
#include <algorithm>
#include <vector>

struct Job
{
    char id;     // Job Id
    int deadline;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    std::sort(arr, arr + n, comparison);

    int maxDeadline = arr[0].deadline;
    for (int i = 1; i < n; i++)
        maxDeadline = std::max(maxDeadline, arr[i].deadline);
    std::vector<int> slots(maxDeadline + 1, -1);

    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    for (int i = 1; i < slots.size(); i++)
        if (slots[i] != -1)
            std::cout << arr[slots[i]].id << " ";
    std::cout << "\nNumber of jobs performed is " << countJobs << " and max profit is " << jobProfit << std::endl;

}

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Following is maximum profit sequence of jobs \n";
    printJobScheduling(arr, n);
    return 0;
}

