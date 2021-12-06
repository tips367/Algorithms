/* Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 

Example:

Input:
Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;

Output:
Maximum possible value = 240
by taking items of weight 10 and 20 kg and 2/3 fraction
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
*/

#include <iostream>
#include <algorithm>

class Item 
{
public:
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, int W)
{
    // sorting Item on basis of ratio
    std::sort(arr, arr + n, cmp);

    int curWeight = 0; 
    double finalvalue = 0.0; 

    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += ((double)arr[i].value / (double)arr[i].weight) * remain;
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int W = 50;     // Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Maximum value we can obtain = " << fractionalKnapsack(arr, n, W);
    return 0;
}

