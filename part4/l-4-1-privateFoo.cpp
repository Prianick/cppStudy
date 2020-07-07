/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 */
#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

struct Foo2 : Foo {
public:
    Foo2(const char *msg) : Foo(msg) {
        return ;
    }
private:
    const char *msg;
};

void foo_says(const Foo &foo) { foo.say(); }



// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

Foo get_foo(const char *msg) {
    Foo2 p(msg);
    Foo p2 = p;
    return p2;
}

int main() {
    foo_says(get_foo("some text"));
}