#include <iostream>

using namespace std;

void strcat(char *to, const char *from)
{

    while(*to) {
    	to++;
    }
    while(*from) {
    	*to = *from;
    	from++;
    	to++;
    }
    *to = '\0';
}

int main()
{
	char str1[20] = "sadasd";
	char str2[] = "_sdfev";

	cout << str1 << endl;

	strcat2(str1, str2);


	cout << str1 << endl;

	return 0;
}
