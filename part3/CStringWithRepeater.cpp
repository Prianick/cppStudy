#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    String(size_t n, char c) {
        this->size = n;
        this->str = new char[n + 1];
        int i = 0;
        while (i < n) {
            this->str[i] = c;
            i++;
        }
        this->str[i] = '\0';
    }

    ~String() {
        delete[] this->str;
    }

    size_t size;
    char *str;
};

int main() {

    char *j;
    j = new char[100];
    delete[] j;

    size_t count = 5;
    char str = 'd';
    char res[] = "";

    String a(count, str);

    int i = 0;
    while (*a.str) {
        res[i] = *a.str;
        a.str++;
        i++;
    }
    // после того как мы собрали все элементы из массива возвращаем указатель но начало массива
    // вот так можно определить начало массива
    i = 1;
    while (a.str[-i] != '\0') {
        i++;
    }
    a.str = a.str - i + 1;
    std::cout << a.size;

    std::cout << res;
}