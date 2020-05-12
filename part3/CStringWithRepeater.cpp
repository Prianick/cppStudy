#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char [this->size + 1];
        strcpy(this->str, str);
        this->str[this->size] = '\0';
    }

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
        this->moveIndexToStartOfString();
        delete[] this->str;
    }

    size_t size;
    char *str;

    // после того как мы собрали все элементы из массива возвращаем указатель но начало массива
    // вот так можно определить начало массива
    void moveIndexToStartOfString() {
        int i = 1;
        while (this->str[-i] != '\0') {
            i++;
        }
        this->str = this->str - i + 1;
    }
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

    std::cout << a.size << std::endl;

    std::cout << res << std::endl;

    String b = "sadds";

    std::cout << b.str;
}