#include <iostream>

using namespace std;

unsigned strlen(char *str)
{
	unsigned len = 0;

	while (str[len] != '\0') {
		++len;
	}

	return len;
}

int main()
{
	char str[15] = "asdsafasf";

	unsigned len = 0;

	len = strlen(str);

	cout << len << endl;

	return 0;
}