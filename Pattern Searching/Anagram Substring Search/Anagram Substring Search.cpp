/* Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences 
of pat[] and its permutations (or anagrams) in txt[]. You may assume that n > m. 

Examples: 

Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
Output:   Found at Index 0
          Found at Index 5
          Found at Index 6
*/

#include <iostream>
#include <string>
#include <vector>

bool compare(std::vector<char>& v1, std::vector<char>& v2)
{
    for (int i = 0; i < size(v1); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}

void search(std::string& txt, std::string& pat)
{
    int txtLen = size(txt);
    int patLen = size(pat);

    // countPat: Store count of all characters of pattern
    // countWin: Store count of current window of text
    std::vector<char> countPat(256, 0);
    std::vector<char> countWindow(256, 0);

    for (int i = 0; i < patLen; i++)
    {
        (countPat[pat[i]])++;
        (countWindow[txt[i]])++;
    }

    // Traverse through remaining characters of pattern
    for (int i = patLen; i < txtLen; i++)
    {
        // Compare counts of current window of text with counts of pattern
        if (compare(countPat, countWindow))
            std::cout << "Found at Index " << (i - patLen) << std::endl;

        // Add current character to current window
        (countWindow[txt[i]])++;

        // Remove the first character of previous window
        countWindow[txt[i - patLen]]--;
    }

    // Check for the last window in text
    if (compare(countPat, countWindow))
        std::cout << "Found at Index " << (txtLen - patLen) << std::endl;
}

int main()
{
    std::string txt = "BACDGABCDA";
    std::string pat = "ABCD";
    search(txt, pat);
    return 0;
}
