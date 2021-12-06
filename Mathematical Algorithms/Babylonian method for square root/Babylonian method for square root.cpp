// Babylonian method for square root

#include <iostream>

float squareRoot(float n)
{
	float x = n;
	float y = 1;
	float e = 0.000001; // e decides the accuracy level
	while (x - y > e) 
	{
		x = (x + y) / 2;
		y = n / x;
	}

	return x;
}

int main()
{
	int n = 50;
	std::cout << "Square root of " << n << " is " << squareRoot(n);

	return 0;
}