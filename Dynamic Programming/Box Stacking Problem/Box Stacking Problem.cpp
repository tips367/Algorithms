/* You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) 
(all real numbers). You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top 
of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of 
the higher box i.e both length and breadth. Of course, you can rotate a box so that any side functions as its base. 
It is also allowable to use multiple instances of the same type of box.

Example :

For example, 
Input  : Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }
Output : The maximum possible height of stack is 60

Following are all rotations of the boxes in decreasing order of base area.

   10 x 12 x 32
   12 x 10 x 32
   32 x 10 x 12
   4 x 6 x 7
   4 x 5 x 6
   6 x 4 x 7
   5 x 4 x 6
   7 x 4 x 6
   6 x 4 x 5
   1 x 2 x 3
   2 x 1 x 3
   3 x 1 x 2

The height 60 is obtained by boxes { {3, 1, 2}, {1, 2, 3}, {6, 4, 5}, {4, 5, 6}, {4, 6, 7}, {32, 10, 12}, {10, 12, 32}}
*/

#include <iostream>
#include <algorithm>

struct Box
{
    // for simplicity assume l>=b
    int l, b, h;
};

int compare(const void* a, const void* b)
{
    return ((*(Box*)b).l * (*(Box*)b).b) -
           ((*(Box*)a).l * (*(Box*)a).b);
}

// Method: Dynamic programming....Time complexity : O(n^2) Space : 0(n) 
int maxStackHeight(Box arr[], int n)
{
    // Array for storing all rotations of the box
    Box* rotationArr = new Box[3*n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        // Copy original box
        rotationArr[index].h = arr[i].h;
        rotationArr[index].l = std::max(arr[i].l, arr[i].b);
        rotationArr[index].b = std::min(arr[i].l, arr[i].b);
        index++;

        // First rotation of box
        rotationArr[index].h = arr[i].l;
        rotationArr[index].l = std::max(arr[i].h, arr[i].b);
        rotationArr[index].b = std::min(arr[i].h, arr[i].b);
        index++;

        // Second rotation of box
        rotationArr[index].h = arr[i].b;
        rotationArr[index].l = std::max(arr[i].h, arr[i].l);
        rotationArr[index].b = std::min(arr[i].h, arr[i].l);
        index++;
    }
    // Now number of box is 3n
    n = 3 * n;
    // Sort the rotationArr[] in non-increasing order of base area
    qsort(rotationArr, n, sizeof(rotationArr[0]), compare);
    
    // msh[i] - Maximum possible Stack Height with box i on top
    int* msh = new int[n];
    for (int i = 0; i < n; i++)
    {
        msh[i] = rotationArr[i].h;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rotationArr[i].l < rotationArr[j].l && rotationArr[i].b < rotationArr[j].b && msh[i] < msh[j] + rotationArr[i].h)
            {
                msh[i] = msh[j] + rotationArr[i].h;
            }
        }
    }
    return *std::max_element(msh, msh + n);
}

/* Driver program to test above function */
int main()
{
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The maximum possible height of stack is " << maxStackHeight(arr, n);
    return 0;
}