#include <iostream>

int main()
{
	char c = '\0';
	char prevS = '\0';

	while (std::cin.get(c)) {
		if (c != ' ' || (c == ' ' && prevS != ' ')) {
			std::cout << c;
		}
		prevS = c;
	}

	return 0;
}
