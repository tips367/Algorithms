/* You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor 
where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

1. If egg breaks at ith floor then it also breaks at all greater floors.
2. If egg does not break at ith floor then it does not break at all lower floors.
3. Unbroken egg can be used again.

Note: You have to find minimum trials required to find the critical floor not the critical floor.

Example :

Input-1:
4
2
Output-1:
Number of trials when number of eggs is 2 and number of floors is 4: 3

Input-2:
36
2
Output-2:
Number of trials when number of eggs is 2 and number of floors is 36: 8
*/

#include <iostream>
#include <algorithm>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
int eggDrop(int totalEggs, int totalFloors)
{  
    // If we have 0 floors we need 0 trials, no matter the egg amount given
    // If we have 1 floor we need 1 trial, no matter the egg amount given
    if (totalFloors == 0 || totalFloors == 1)
        return totalFloors;
    // If we have 1 egg...no matter what floors we get, our approach will be to do 'floorAmount' drops...this is because we want to start from
    //  floor 1, drop...then go to floor 2, drop...and so on until we get to in the worst case 'floorAmount'
    if (totalEggs == 1)
        return totalFloors;
    int min = INT_MAX;
    // We do a theoretical test on every floor from 1 to the 'floor' amount for this subproblem.
    // At each 'attemptFloor' we express both possibilities described below
    for (int attemptFloor = 1; attemptFloor <= totalFloors; attemptFloor++) 
    {
        // We want to know the cost of the 2 outcomes:
        //    1.) We drop an egg and it breaks. We move 1 floor down. We have 1 less egg.
        //    2.) We drop an egg and it doesn't break. We have this many floors left: the difference between the total floors and our current
        //    floor. We have the same number of eggs.        
        int costOfWorstOutcome = std::max(eggDrop(totalEggs-1, attemptFloor-1), eggDrop(totalEggs, totalFloors - attemptFloor));
        if (costOfWorstOutcome < min)
            min = costOfWorstOutcome;
    }
    // After we get the cost of the WORST outcome we add 1 to that worst outcome
    // to simulate the fact that we are going to do a test from THIS subproblem.
    return min + 1;
} */

// Method 2. Dynamic programming....Time complexity : O(totalEggs*totalFloors^2)  Space : O(totalEggs*totalFloors)
int eggDrop(int totalEggs, int totalFloors)
{
    std::vector<std::vector<int>> eggFloor(totalEggs + 1, std::vector<int>(totalFloors + 1)); // similar to eggFloor[totalEggs+1][totalFloors+1];
    // If we have 0 floors we need 0 trials, no matter the egg amount given
    // If we have 1 floor we need 1 trial, no matter the egg amount given
    for (int eggs = 1; eggs <= totalEggs; ++eggs)
    {
        eggFloor[eggs][0] = 0;
        eggFloor[eggs][1] = 1;
    }
    // If we have 1 egg...no matter what floors we get, our approach will be to do 'floorAmount' drops...this is because we want to start from
    //  floor 1, drop...then go to floor 2, drop...and so on until we get to in the worst case 'floorAmount'
    for (int floor = 1; floor <= totalFloors; ++floor)
    {
        eggFloor[1][floor] = floor;
    }
    // Solve the rest of the subproblems
    for (int eggs = 2; eggs <= totalEggs; ++eggs)
    {
        for (int floor = 2; floor <= totalFloors; ++floor)
        {
            eggFloor[eggs][floor] = INT_MAX;
            // We do a theoretical test on every floor from 1 to the 'floor' amount for this subproblem.
            // At each 'attemptFloor' we express both possibilities described below
            for (int attemptFloor = 1; attemptFloor <= floor; ++attemptFloor)
            {
                // We want to know the cost of the 2 outcomes:
                //    1.) We drop an egg and it breaks. We move 1 floor down. We have 1 less egg.
                //    2.) We drop an egg and it doesn't break. We have this many floors left: the difference between the total floors and our current
                //    floor. We have the same number of eggs.        
                int costOfWorstOutcome = std::max(eggFloor[eggs - 1][attemptFloor - 1], eggFloor[eggs][floor - attemptFloor]);
                // After we get the cost of the WORST outcome we add 1 to that worst outcome
                // to simulate the fact that we are going to do a test from THIS subproblem.
                int accountingForDroppingAtThisSubproblem = 1 + costOfWorstOutcome;
                // Did we reach a BETTER (lower) amount of drops that guarantee that we can find the pivotal floor where eggs begin to break?
                eggFloor[eggs][floor] = std::min(eggFloor[eggs][floor], accountingForDroppingAtThisSubproblem);
            }
        }
    }
    return eggFloor[totalEggs][totalFloors];
}

// Driver program
int main()
{
    int n = 2, k = 10;
    std::cout << "Minimum number of trials "
        "in worst case with "
        << n << " eggs and " << k
        << " floors is "
        << eggDrop(n, k) << std::endl;
    return 0;
}