// Check if a Number is Multiple of 3

#include <iostream>

bool isMultipleOf3(int num)
{
    int oddCount = 0;
    int evenCount = 0;  
    
    // Make no positive if +n is multiple of 3 then is -n
    if (num < 0)
        num = -num;
    if (num == 0)
        return true;
    if (num == 1)
        return false;

    while (num)
    {
        if (num & 1)
            oddCount++;

        if (num & 2)
            evenCount++;
        num = num >> 2;
    }

    return isMultipleOf3(abs(oddCount - evenCount));
}

int main()
{
    int num = 18;
    if (isMultipleOf3(num))
        printf("%d is multiple of 3", num);
    else
        printf("%d is not a multiple of 3", num);
    return 0;
}


