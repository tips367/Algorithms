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

void search(std::string& txt, std::string& pat)
{
    int M = size(pat);
    int N = size(txt);

    for (int i = 0; i <= N - M; i++) 
    {
        int j;
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            std::cout << "Pattern found at index " << i << std::endl;
    }
}

int main()
{
    std::string txt = "AABAACAADAABAAABAA";
    std::string pat = "AABA";
    search(txt, pat);
    return 0;
}
