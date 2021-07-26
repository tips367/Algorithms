/* Given a boolean expression with following symbols. 

Symbols
    'T' ---> true 
    'F' ---> false 
And following operators filled between symbols 

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Examples:

Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, T, F, T}
       operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T))
*/

#include <iostream>
#include <string>
#include <vector>

int countParenthesization(std::string symbols, std::string operators)
{
    int n = symbols.length();

    std::vector<std::vector<int>> dpT(n, std::vector<int>(n));
    std::vector<std::vector<int>> dpF(n, std::vector<int>(n));

    // All diagonal entries in dpT[i][i] are 1 if symbols[i] is T (true).  Similarly,
    // all dpF[i][i] entries are 1 if symbols[i] is F (False)
    for (int i = 0; i < n; i++)
    {
        if (symbols[i] == 'T')
        {
            dpT[i][i] = 1;
            dpF[i][i] = 0;
        }
        else
        {
            dpT[i][i] = 0;
            dpF[i][i] = 1;
        }
    }

    for (int currLen = 2; currLen <= n; currLen++)
    {
        for (int i = 0; i < n - currLen + 1; i++)
        {
            int j = i + currLen - 1;
            for (int k = i; k < j; k++)
            {
                int leftTrueCount = dpT[i][k];
                int rightTrueCount = dpT[k + 1][j];
                int leftFalseCount = dpF[i][k];
                int rightFalseCount = dpF[k + 1][j];

                if (operators[k] == '&')
                {
                    dpT[i][j] += leftTrueCount * rightTrueCount;
                    dpF[i][j] += leftTrueCount * rightFalseCount + leftFalseCount * rightTrueCount + leftFalseCount * rightFalseCount;        
                }
                else if (operators[k] == '|')
                {
                    dpT[i][j] += leftTrueCount * rightFalseCount + leftFalseCount * rightTrueCount + leftTrueCount * rightTrueCount;
                    dpF[i][j] += leftFalseCount * rightFalseCount;
                }
                else     // '^'
                {
                    dpT[i][j] += leftFalseCount * rightTrueCount + leftTrueCount * rightFalseCount;
                    dpF[i][j] += leftFalseCount * rightFalseCount + leftTrueCount * rightTrueCount;
                }
            }
        }
    }
    return dpT[0][n-1];
}

int main()
{
    std::string symbols = "TTFT";
    std::string operators = "|&^";

    std::cout << countParenthesization(symbols, operators);
    return 0;
}


