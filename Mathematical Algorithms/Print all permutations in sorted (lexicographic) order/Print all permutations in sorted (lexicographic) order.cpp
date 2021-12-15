/* Given a string, print all permutations of it in sorted order. For example, if the input string is “ABC”, then output should be
“ABC, ACB, BAC, BCA, CAB, CBA”.
*/

#include <iostream>
#include <algorithm>

bool nextPermutation(std::string& s)
{
    int n = size(s);
    if (n <= 1)
        return false;
    int i, j;
    for (i = n - 2; i >= 0; --i)
    {
        if (s[i] < s[i + 1])
            break;
    }

    if (i < 0)
        return false;

    for (j = n - 1; j > i; --j)
    {
        if (s[j] > s[i])
            break;
    }
    std::swap(s[i], s[j]);
    std::reverse(s.begin() + i + 1, s.end());
    return true;
}

int main()
{
    std::string s = "ABCD";
    std::sort(s.begin(), s.end());
    do
    {
        std::cout << s << std::endl;
    } while (nextPermutation(s));
        
    return 0;
}

