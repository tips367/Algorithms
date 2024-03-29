/* Lucky numbers are subset of integers. Let us see the process of arriving at lucky numbers, 
Take the set of integers 
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,��
First, delete every second number, we get following reduced set. 
1,3,5,7,9,11,13,15,17,19,����

Now, delete every third number, we get 
1, 3, 7, 9, 13, 15, 19,�.�.

Continue this process indefinitely�� 
Any number that does NOT get deleted due to above process is called �lucky�.
Therefore, set of lucky numbers is 1, 3, 7, 13,���
Now, given an integer �n�, write a function to say whether this number is lucky or not. 
*/

#include <iostream>

bool isLucky(int num, int& iteration)
{
    if (iteration > num)
        return true;

    if (num % iteration == 0)
        return false;

    int next_position = num - (num / iteration);
    iteration++;
    return isLucky(next_position, iteration);
}

int main()
{
    int x = 19;
    int iteration = 2;
    if (isLucky(x, iteration))
        std::cout << x << " is a lucky no.";
    else
        std::cout << x << " is not a lucky no.";
}
