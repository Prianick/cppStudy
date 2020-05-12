#include <iostream>
#include <string>
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

//    void append(String &other) {
//        size_t max = this->size + other.size + 1;
//        char *c = new char[max];
//        strcpy(c, this->str);
//        strcat(c + this->size, other.str);
//        delete[] this->str;
//        *(c + max) = '\0';
//        this->str = c;
//        this->size = max - 1;
//    }


    ~String() {
//        this->moveIndexToStartOfString();
        delete[] this->str;
    }

    size_t size;
    char *str;

    // после того как мы собрали все элементы из массива возвращаем указатель но начало массива
    // вот так можно определить начало массива
//    void moveIndexToStartOfString() {
//        int i = 1;
//        while (this->str[-i] != '\0') {
//            i++;
//        }
//        this->str = this->str - i + 1;
//    }
};


int main() {

    const size_t ntest = 10;

    std::string tests[ntest][2] = {
            {"",                     ""},
            {"",                     "test"},
            {"test",                 ""},
            {"test",                 "test"},
            {"Hello ",               " world!"},
            {"Supercalifragilistic", "expialidocious"},
            {"Supercalifragilistic", "expialidocious"},
            {"Supercalifragilistic", "expialidocious"},
            {"Supercalifragilistic", "expialidocious"},
            {"Supercalifragilistic", "expialidocious"}
    };

    for (size_t i = 0; i < ntest; ++i) {
        String t1(tests[i][0].c_str());
        String t2(tests[i][1].c_str());

        t1.append(t2);

        std::string res(t1.str);
        if (res != tests[i][0] + tests[i][1]) {
            std::cout << "Test " << i + 1 << " failed!" << std::endl;
            std::cout << "Must be " << tests[i][0] + tests[i][1] << std::endl;
            std::cout << "But result is " << res << std::endl;
        } else {
            std::cout << "Test " << i + 1 << " passed!" << std::endl;
        }
    }

    std::string last = "Same pointer test";
    String t(last.c_str());
    t.append(t);

    std::string res(t.str);

    if (res != last + last) {
        std::cout << "Test " << ntest + 1 << " failed!" << std::endl;
        std::cout << "Must be " << last + last << std::endl;
        std::cout << "But result is " << res << std::endl;
    } else {
        std::cout << "Test " << ntest + 1 << " passed!" << std::endl;
    }

    return 0;
}

//int main() {
//
//    char *j;
//    j = new char[100];
//    delete[] j;
//
//    size_t count = 5;
//    char str = 'd';
//    char res[] = "";
//
//    String a(count, str);
//
//    int i = 0;
//    while (i < a.size) {
//        res[i] = a.str[i];
//        i++;
//    }
//
//    std::cout << a.size << std::endl;
//
//    std::cout << res << std::endl;
//
//    String b = "sadds";
//    String c = "1234";
//
//    b.append(c);
//    std::cout << b.str;
//}