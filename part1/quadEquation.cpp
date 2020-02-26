#include <iostream>
#include <cmath>

int main() 
{
	int a, b, c;
	double D;
	double r1, r2;

	std::cin >> a >> b >> c;

	D = b * b - 4 * (a * c);

	if (D < 0) {
		std::cout << "No real roots";
	} else {
		r1 = (-b + sqrt(D)) / (2 * a);
		std::cout << r1 << " ";
		
		r2 = (-b - sqrt(D)) / (2 * a);
		std::cout << r2;	
	}

	std::cout << std::endl;

	return 0;
}