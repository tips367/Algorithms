/* Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences
of pat[] in txt[]. You may assume that n > m.

Examples:

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
*/

#include <iostream>
#include <vector>

std::vector<int> kmpPreprocess(std::string const& needle)
{
    int n = size(needle);
    std::vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n)
    {
        if (needle[len] == needle[i])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

void KMPSearch(std::string txt, std::string pattern)
{
    int patLen = size(pattern);
    if (patLen == 0)
        return;
    int txtLen = size(txt);

    std::vector<int> lps = kmpPreprocess(pattern);
    int i = 0, j = 0;
    while (i < txtLen)
    {
        if (txt[i] == pattern[j])
            ++i, ++j;
        else
            j ? j = lps[j - 1] : ++i;
        if (j == patLen)
        {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        }

    }
}

int main()
{
    std::string txt = "AABAACAADAABAABA";
    std::string pat = "AABA";
    KMPSearch(txt, pat);
    return 0;
}