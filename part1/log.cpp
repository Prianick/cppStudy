#include <iostream>

int log(int a) {

	int p = 1;
	int x = 2;

	while (x <= a) {
		x = x * 2;
		p = p + 1;
	}

	return p - 1;
}

int main() { 
	int count;
    int counter = 1;
    int a;
    int exp;

    std::cin >> count;

    while(counter <= count) {
        std::cin >> a;
        exp = log(a);
    	std::cout << exp << std::endl;
    	counter++;
    }

    return 0;
}
