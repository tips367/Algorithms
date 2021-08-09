/* Given an input number of sections and each section has 2 plots on either sides of the road. 
Find all possible ways to construct buildings in the plots such that there is a space between any 2 buildings.

Example :

N = 1
Output = 4
Place a building on one side.
Place a building on other side
Do not place any building.
Place a building on both sides.

N = 3
Output = 25
3 sections, which means possible ways for one side are BSS, BSB, SSS, SBS, SSB where B represents a building
and S represents an empty space.
Total possible ways are 25, because a way to place on one side can correspond to any of 5 ways on other side.
*/

#include <iostream>

int countWays(int n)
{
    if (n == 0)
        return 0;

    int prevCountB = 1;
    int prevCountS = 1;

    for (int i = 2; i <= n; i++)
    {
        // countB is count of ways with a building at the end
        // countS is count of ways with a space at the end
        int countB = prevCountS;
        int countS = prevCountB + prevCountS;

        prevCountB = countB;
        prevCountS = countS;
    }
    
    // Total ways for one side is sum of ways ending with building and ending with space
    int total = prevCountB + prevCountS;

    // Total ways for 2 sides is square of total ways for one side
    return total * total;
}

int main()
{
    int N = 3;
    std::cout << "Count of ways for " << N << " sections is " << countWays(N);
    return 0;
}
