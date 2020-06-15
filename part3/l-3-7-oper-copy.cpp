#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char[this->size + 1];
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
        delete[] this->str;

    }

    /* Реализуйте конструктор копирования */
    String(const String &other) : size(other.size), str(new char[other.size + 1]) {
        unsigned i = 0;
        while (i < size + 1) {
            str[i] = other.str[i];
            i++;
        }
    }

    void append(String &other) {
        size_t newSize = size + other.size;
        char *temp = new char[newSize + 1];
        int i = 0;
        while (i < size) {
            temp[i] = str[i];
            i++;
        }
        int j = 0;
        while (j < other.size) {
            temp[i] = other.str[j];
            j++;
            // Здесь(i) после последней итерации будет уже нужный индекс. В операторе while он проверит,
            // что он больше size и не зайдет сюда снова, но когда мы будем вставлять '\0' единицу уже вставлять не надо.
            i++;
        }
        temp[i] = '\0';
        size = newSize;
        delete[] str;
        str = temp;
    }

    size_t size;
    char *str;
};

int main() {
    std::cout << "hello" << std::endl;
    String str1 = "21414sdfad" ;
    String str2 = str1;
    std::cout << str1.str << std::endl << "sad" << std::endl;
    String str3 = "2323";
    str1.append(str3);
    std::cout << str2.str << std::endl;
    std::cout << str1.str << std::endl;
}
