/* Given a dictionary, and two words ‘start’ and ‘target’ (both of same length). Find length of the smallest chain from ‘start’ to ‘target’ 
if it exists, such that adjacent words in the chain only differ by one character and each word in the chain is a valid word i.e., 
it exists in the dictionary. It may be assumed that the ‘target’ word exists in dictionary and length of all dictionary words is same.

Example:

Input: Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}
       start = TOON
       target = PLEA
Output: 7
TOON - POON - POIN - POIE - PLIE - PLEE - PLEA

Input: Dictionary = {ABCD, EBAD, EBCD, XYZA}
       Start = ABCV
       End = EBAD
Output: 4
ABCV - ABCD - EBCD - EBAD
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
    // If the endWord is not present in the dictionary
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;

    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    std::queue<std::string> q;
    q.push(beginWord);

    int depth = 0;
    while (!q.empty())
    {
        ++depth;
        int count = q.size();
        while (count--)
        {
            std::string word = q.front();
            q.pop();
            int n = word.size();

            // For every character of the word
            for (int i = 0; i < n; ++i)
            {
                std::string temp = word;

                // Replace the current character with every possible lowercase alphabet
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    temp[i] = c;
                    if (temp == word)
                        continue;
                    if (temp == endWord)
                        return depth + 1;
                    if (wordSet.find(temp) != wordSet.end())
                    {
                        // push the newly generated word which will be a part of the chain
                        q.push(temp);
                        wordSet.erase(temp);
                    }
                }
            }

        }
    }
    return 0;
}

int main()
{
    std::string beginWord = "toon";
    std::string endWord = "plea";
    std::vector<std::string> wordList = { "poon", "plee", "same", "poie", "plie", "poin", "plea" };
    std::cout << "Length of shortest chain is: " << ladderLength(beginWord, endWord, wordList);
}

