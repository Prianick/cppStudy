#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {

    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char [this->size + 1];
        strcpy(this->str, str);
        this->str[this->size] = '\0';
    }

    ~String() {
        delete [] this->str;
    };

    size_t size;
    char *str;
};

int main() {

    char str[] = "stringsss";

    char str2[20] = "";
    char * dstr = str2;

    String a = str;

    std::cout << a.str;
    while (*a.str) {
        *dstr = *a.str;
        dstr++;
        a.str++;
    }
    int stop = 1;
}