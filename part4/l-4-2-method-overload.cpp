#include <iostream>

struct String {
    // конструктор
    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char[this->size + 1];
        strcpy(this->str, str);
        this->str[this->size] = '\0';
    }

    // конструктор
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

    // деструктор
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

    // конструктор присваивания
    String &operator=(const String &other) {
        if (this != &other) {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            unsigned i = 0;
            while (i < size + 1) {
                str[i] = other.str[i];
                i++;
            }
        }

        return *this;
    }

    // метод
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

    char &at(size_t idx) {
        return str[idx];
    }

    char at(size_t idx) const {
        return str[idx];
    }

    size_t size;
    char *str;
};

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }

int main() {
    String greet("Hello");
    char ch1 = greet.at(0);
    printf("\n %c", ch1);

    String const const_greet("Hello, Const!");
    char const &ch2 = const_greet.at(0);

    printf("\n %c", ch2);

    short sh = 10;
    promotion(sh);

}
