#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_str = new char[new_size];
    unsigned i = 0;
	while (i < size && i < new_size) {
		new_str[i] = str[i];
        i++;
	}
    delete[]str;
	return new_str;
}


int main(int argc, char const *argv[])
{
//    int * m;
//    m = new int [1000]; // https://prog-cpp.ru/cpp-newdelete/
//    delete [] m;

    char * m = new char[1000];
	char * newM;

	m[0] = 'h';
	m[1] = 'i';

	newM = resize(m, 1000, 2000);
	std::cout << newM << std::endl;
	return 0;
}
