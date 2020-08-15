/* Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative.
In other words, no matter how we parenthesize the product, the result will be the same.
For example, if we had four matrices A, B, C, and D, we would have:
(ABC)D = (AB)(CD) = A(BCD) = ....

Example :

Input: p[] = {40, 20, 30, 10, 30}
Output: 26000

There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. Let the input 4 matrices be A, B, C and D.  The minimum number of
multiplications are obtained by putting parenthesis in following way : (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
*/

#include <iostream>
#include <vector>

// Method 1: Recursion....Time complexity : Exponential
/*
int matrixChainMultiplication(int dims[], int i, int j)
{
	// base case : one matrix
	if (i == j)
		return 0;
	int min = INT_MAX;

	// take the minimum over each possible position at which the
	// sequence of matrices can be split

	//	(M[i]) x (M[i+1]..................M[j])
	//	(M[i]M[i+1]) x (M[i+2].............M[j])
	//	...
	//	...
	//	(M[i]M[i+1]............M[j-1]) x (M[j])

	for (int k = i; k < j; k++)
	{
		// recur for M[i]..M[k] to get an i x k matrix
		int cost = matrixChainMultiplication(dims, i, k);

		// recur for M[k+1]..M[j] to get a k x j matrix
		cost += matrixChainMultiplication(dims, k+1, j);

		// cost to multiply two (i x k) and (k x j) matrix
		cost += dims[i-1] * dims[k] * dims[j];

		if (cost < min)
			min = cost;
	}

	return min;
}

// Driver Code
int main()
{
	// Matrix M[i] has dimension dims[i-1] x dims[i] for i = 1..n
	// input is 10 × 30 matrix, 30 × 5 matrix, 5 × 60 matrix
	int dims[] = { 10, 30, 5, 60 };
	int n = sizeof(dims) / sizeof(dims[0]);

	std::cout << "Minimum number of multiplications is "
		<< matrixChainMultiplication(dims, 1, n - 1);
	return 0;
}
*/

// Method 2. Dynamic programming....Time complexity : O(n^3)  Space : O(n^2)
void printParenthesis(int i, int j, std::vector<std::vector<int>> const& bracket, char& name);
int matrixChainMultiplication(int dims[], int n)
{
	// c[i,j] = Minimum number of scalar multiplications i.e. cost needed to compute the matrix M[i]M[i+1]...M[j] = M[i..j] where
	// dimension of M[i] is dims[i-1] x dims[i] 
	std::vector<std::vector<int>> c(n, std::vector<int>(n)); // similar to c[n][n];

	// bracket[i][j] stores optimal break point in subexpression from i to j.
	std::vector<std::vector<int>> bracket(n, std::vector<int>(n));

	// cost is zero when multiplying one matrix. 
	for (int i = 1; i < n; i++)
	{
		c[i][i] = 0;
	}
	// L is chain length. 
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			c[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int cost = c[i][k] + c[k + 1][j] +
					dims[i - 1] * dims[k] * dims[j];
				if (cost < c[i][j])
				{
					c[i][j] = cost;
					// Each entry bracket[i,j]=k shows where to split the product arr i,i+1....j for the minimum cost.
					bracket[i][j] = k;
				}
			}
		}
	}
	char name = 'A';
	std::cout << "Optimal Parenthesization is : ";
	printParenthesis(1, n - 1, bracket, name);
	return c[1][n - 1];
}

// Function for printing the optimal parenthesization of a matrix chain product 
void printParenthesis(int i, int j, std::vector<std::vector<int>> const& bracket, char& name)
{
	// If only one matrix left in current segment 
	if (i == j)
	{
		std::cout << name++;
		return;
	}

	std::cout << "(";

	// Recursively put brackets around subexpression from i to bracket[i][j]. 
	printParenthesis(i, bracket[i][j], bracket, name);

	// Recursively put brackets around subexpression from bracket[i][j] + 1 to j. 
	printParenthesis(bracket[i][j] + 1, j, bracket, name);
	std::cout << ")";
}

// Driver Code 
int main()
{
	// Matrix M[i] has dimension dims[i-1] x dims[i] for i = 1..n
	// input is 3 × 2 matrix, 2 × 4 matrix, 4 × 2 matrix, 2 × 5 matrix
	int dims[] = { 3,2,4,2,5 };
	int n = sizeof(dims) / sizeof(dims[0]);

	std::cout << "\nMinimum number of multiplications is "
		<< matrixChainMultiplication(dims, n);
	return 0;
}