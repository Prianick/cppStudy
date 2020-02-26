#include <iostream>

// Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:

// GCD(a, b) = GCD(b, a \bmod b)GCD(a,b)=GCD(b,amodb)
// GCD(0, a) = aGCD(0,a)=a
// GCD(a, b) = GCD(b, a)GCD(a,b)=GCD(b,a)
// Требования к реализации: в данном задании запрещено пользоваться циклами. Вы можете заводить любые вспомогательные функции, если они вам нужны. Функцию main определять не нужно.


int check(unsigned a, unsigned b, unsigned c) {
	if (a % c == 0 && b % c == 0) {
		return c;
	}
	return check(a, b, --c);
}

unsigned gcd(unsigned a, unsigned b)
{
	int c = 0;

	if (a == 0 || b == 0) {
		return a + b;
	}

	if (a > b) {
		c = b;
	} else {
		c = a;
	}

    return check(a, b, c);
}

int main(int argc, char const *argv[])
{
	int a, b;

	std::cin >> a >> b;

	std::cout << gcd(a, b) << std::endl;
	return 0;
}