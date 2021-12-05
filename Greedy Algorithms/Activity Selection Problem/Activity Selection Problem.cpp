/* You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a 
single person, assuming that a person can only work on a single activity at a time.

Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The maximum set of activities that can be executed is {0, 2} 
[ These are indexes in start[] and finish[] ]

Example 2 : Consider the following 6 activities
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Method 1
/*
void printMaxActivities(std::vector<std::vector<int>>& activities)
{
    int n = size(activities);
    // Sort jobs according to finish time
    std::sort(activities.begin(), activities.end(), [&](std::vector<int>& a, std::vector<int>& b) {
        return a[1] < b[1];
        });

    std::cout << "Following activities are selected \n";

    // The first activity always gets selected
    int prev = 0;
    std::cout << "(" << activities[prev][0] << ", " << activities[prev][1] << "), ";

    for (int i = 1; i < n; ++i)
    {
        // If this activity has start time greater than or equal to the finish time of previously selected
        // activity, then select it
        if (activities[i][0] >= activities[prev][1])
        {
            std::cout << "(" << activities[i][0] << ", " << activities[i][1] << "), ";
            prev = i;
        }
    }
} */

// Method 2: Using Priority queue
void printMaxActivities(std::vector<std::vector<int>>& activities)
{
    int n = size(activities);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({ activities[i][1], activities[i][0] });
    }

    std::vector<int> firstActivity = pq.top();
    pq.pop();
    int start = firstActivity[1];
    int end = firstActivity[0];
    std::cout << "(" << start << ", " << end << "), ";

    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();
        if (itr[1] >= end)
        {
            start = itr[1];
            end = itr[0];
            std::cout << "(" << start << ", " << end << "), ";
        }
    }
}

int main()
{
    std::vector<std::vector<int>> activities = { {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9} };
    printMaxActivities(activities);
    return 0;
}


