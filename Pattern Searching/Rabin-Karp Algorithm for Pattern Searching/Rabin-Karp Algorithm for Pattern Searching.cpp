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
#include <string.h>

#define d 256

void search(std::string& txt, std::string& pattern)
{
    int txtLen = size(txt);
    int patternLen = size(pattern);
    int prime = 101;

    int h = 1;
    // The value of h would be "pow(d, patternLen-1)%prime" 
    for (int i = 0; i < patternLen - 1; i++)
        h = (h * d) % prime;

    // Calculate the hash value of pattern and first window of text 
    int patternHash = 0, windowHash = 0;
    for (int i = 0; i < patternLen; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % prime;
        windowHash = (d * windowHash + txt[i]) % prime;
    }

    // Slide the pattern over text one by one 
    for (int i = 0; i <= txtLen - patternLen; i++)
    {
        if (patternHash == windowHash)
        {
            int j;
            for (j = 0; j < patternLen; j++)
            {
                if (txt[i + j] != pattern[j])
                    break;
            }

            if(j == patternLen)
                std::cout << "Pattern found at index " << i << std::endl;
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit 
        if (i < txtLen - patternLen)
        {
            windowHash = (d * (windowHash - txt[i] * h) + txt[i + patternLen]) % prime;
            // We might get negative value of windowHash, converting it to positive 
            if (windowHash < 0)
                windowHash = windowHash + prime;
        }
    }
}

int main()
{
    std::string txt = "AABAACAADAABAABA";
    std::string pattern = "AABA";

    search(txt, pattern);
    return 0;
}

