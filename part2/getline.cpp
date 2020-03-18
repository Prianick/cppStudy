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

unsigned strlen(char *str)
{
    unsigned len = 0;

    while (str[len] != '\0') {
        ++len;
    }

    return len;
}

char *getline() {
    char *str = new char[100];
    char c = ' ';
    unsigned i = 0;
    while (std::cin.get(c)) {
        if (c == EOF || c == '\n') {
            break;
        }
        if (i % 100 == 0) {
            str = resize(str, strlen(str), strlen(str) + 100);
        }

        str[i] = c;
        ++i;
    }
    str[i] = '\0';
    return str;
}

int main() {
    char *str = 0;
    str = getline();
    std::cout << str << std::endl;
    delete[]str;
}