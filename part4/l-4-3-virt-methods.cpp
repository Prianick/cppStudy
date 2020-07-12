#include <iostream>

// виртуальные методы
class Person {
public:
    Person(char *str) {
        this->nameSize_ = strlen(str);
        this->name_ = new char[this->nameSize_ + 1];
        strcpy(this->name_, str);
        this->name_[this->nameSize_] = '\0';
    }

    virtual char *occupation() {
        test();
        return name_;
    }

    void test() {
//        this->occupation();
    }

public:
    size_t nameSize_;
    char *name_;
};

class Professor : public Person {
public:
    Professor(char *str) : Person(str) {}

    char *occupation() {
        char pref[] = "Prof. ";
        char *prefP = pref;
        char *p = strconcat(prefP, name_);
        return p;
    }

    char *strconcat(char *dest, char *src) {
        size_t newStrLen = strlen(dest) + strlen(src);
        char *newStr = new char[newStrLen + 1];
        int i = 0;
        while (i < strlen(dest)) {
            newStr[i] = dest[i];
            i++;
        }
        int j = 0;
        while (j < strlen(src)) {
            newStr[i] = src[j];
            i++;
            j++;
        }
        newStr[i] = '\0';
        return newStr;
    }
};

// задание с созданием выражений и чисел

struct Expression {
    virtual double evaluate() const = 0;

    virtual ~Expression() {};
};

struct Number : Expression {
public:
    Number(double value)
            : value(value) {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
public:
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}


    double evaluate() const {
        double res;
        switch (op) {
            case '+':
                res = left->evaluate() + right->evaluate();
                break;
            case '-':
                res = left->evaluate() - right->evaluate();
                break;
            case '*':
                res = left->evaluate() * right->evaluate();
                break;
            case '/':
                res = left->evaluate() / right->evaluate();
                break;
        }
        return res;
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

int demo() {
    int a = 7;
    std::cout << a << '\n'; // выводим значение переменной a
    std::cout << &a << '\n'; // выводим адрес памяти переменной a
    std::cout << *&a << '\n'; // выводим значение ячейки памяти переменной a

    int value = 1;
    int *ptr = &value; // инициализируем ptr адресом значения переменной

    std::cout << "(int *)&value: " << (int *)&value << '\n'; // выводим адрес значения переменной value
    std::cout << "ptr: " << ptr << '\n'; // выводим адрес, который хранит ptr

    int x(4);
    std::cout << "&x: " << typeid(&x).name() << "\n";
    std::cout << "*&x: " << *&x << "\n";
    std::cout << "&x: " << &x << "\n";

    return 0;
}

bool check_equals(Expression const *left, Expression const *right) {
    int * p1 = (int *)left;
    int * p2 = (int *)right;
    return *p1 == *p2;
}


int main() {
    char str[] = "some name";
    char *strP = str;
    Professor pr(strP);
    std::cout << "Prof name: " << pr.occupation() << std::endl;
    pr.test();
    Person prP("some 2 name");
    std::cout << "Person name: " << prP.occupation() << std::endl;

//    // сначала создаём объекты для подвыражения 4.5 * 5
//    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
//    // потом используем его в выражении для +
//    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
//
//    // вычисляем и выводим результат: 25.5
//    std::cout << expr->evaluate() << std::endl;
//
//    // тут освобождаются *все* выделенные объекты
//    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
//    delete expr;

    Expression *num1 = new Number(3);
    Expression *sube1 = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *num2 = new Number(255);

//    demo();

    bool res1 = check_equals(num1, num2);
    std::cout << "res1: " << res1 << std::endl;
    bool res2 = check_equals(num1, sube1);
    std::cout << "res2: " << res2 << std::endl;

    return 1;
}