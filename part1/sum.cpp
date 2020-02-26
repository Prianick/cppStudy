#include <iostream>

int main()
{
    int count;
    int counter = 1;
    int a;
    int b;

    std::cin >> count;

    // std::cout << count;
    // std::cout << counter;

    while(counter <= count) {
        std::cin >> a >> b;
    	std::cout << (a + b) << std::endl;
    	counter++;
    }

    return 0;
}