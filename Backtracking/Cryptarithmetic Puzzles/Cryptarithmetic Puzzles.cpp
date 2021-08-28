/* Newspapers and magazines often have crypt-arithmetic puzzles of the form:
Examples:

Input : s1 = SEND, s2 = "MORE", s3 = "MONEY"
Output : One of the possible solution is: D=1 E=5 M=0 N=3 O=8 R=2 S=7 Y=6  
Explanation:
The above values satisfy below equation : 
  SEND
+ MORE
--------
 MONEY
--------
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

int getNum(std::map<char, int>& uniqueCharMap, std::string s)
{
    std::string num = "";
    for (char ch : s)
    {
        num += std::to_string(uniqueCharMap[ch]);
    }

    return stoi(num);
}

bool valid(std::map<char, int>& uniqueCharMap, std::string s1, std::string s2, std::string s3)
{
    int num1 = getNum(uniqueCharMap, s1);
    int num2 = getNum(uniqueCharMap, s2);
    int num3 = getNum(uniqueCharMap, s3);

    if (num1 + num2 == num3)
        return true;
    return false;
}

void solveCryptarithmeticUtil(std::map<char, int>& uniqueCharMap, std::vector<bool>& usedNumbers, const std::string& uniqueStr, int pos,
    std::string s1, std::string s2, std::string s3)
{
    if (pos == uniqueCharMap.size())
    {
        if (valid(uniqueCharMap, s1, s2, s3))
        {
            for (const auto& a: uniqueCharMap)
                std::cout << " " << a.first << " = " << a.second;
            std::cout << "\n";
        }
        return;
    }

    for (int num = 0; num < 10; num++)
    {
        // if integer not used yet
        if (usedNumbers[num] == false)
        {
            uniqueCharMap[uniqueStr[pos]] = num;
            usedNumbers[num] = true;
            solveCryptarithmeticUtil(uniqueCharMap, usedNumbers, uniqueStr, pos + 1, s1, s2, s3);

            // backtrack for all other possible solutions
            uniqueCharMap[uniqueStr[pos]] = -1;
            usedNumbers[num] = false;
        }
    }
}

void solveCryptarithmetic(std::string s1, std::string s2, std::string s3)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    std::vector<int> frequency(26);

    for (int i = 0; i < l1; i++)
        ++frequency[s1[i] - 'A'];

    for (int i = 0; i < l2; i++)
        ++frequency[s2[i] - 'A'];

    for (int i = 0; i < l3; i++)
        ++frequency[s3[i] - 'A'];

    std::map<char, int> uniqueCharMap;
    std::string uniqueStr = "";

    // store all unique char in uniqueCharMap
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            uniqueCharMap[i + 'A'] = -1;
            uniqueStr += (i + 'A');
        }
    }

    // solution not possible for count greater than 10
    if (uniqueCharMap.size() > 10)
    {
        std::cout << "Invalid strings";
        return;
    }

    // vector stores true corresponding to number which is already assigned to any char, otherwise stores false
    std::vector<bool> usedNumbers(10);

    solveCryptarithmeticUtil(uniqueCharMap, usedNumbers, uniqueStr, 0, s1, s2, s3);
}

int main()
{
    std::string s1 = "SEND";
    std::string s2 = "MORE";
    std::string s3 = "MONEY";

    solveCryptarithmetic(s1, s2, s3);

    return 0;
}


