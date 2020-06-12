#include <iostream>
#include <string>

/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

struct Cls {
    Cls(char c, double d, int i) {
        this->c = c;
        this->d = d;
        this->i = i;
    }

private:
    char c;
    double d;
    int i;
};

struct ClsPubl
{
    /*Суть в том, чтобы подельник был полной копией подозреваемого (только в этом случае поля и методы одного класса будут находится в памяти по тем же смещениям, что и у другого), за исключением наличия семьи и детей.*/
    ClsPubl(char _c, double _d, int _i);
public: /*<--- слабое место в психологии преступника - его близкие.*/
    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    void *objBr = static_cast<void *>(&cls);
    struct ClsPubl *p = static_cast<ClsPubl *>(objBr);
    return p->c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
//    void *objBr = static_cast<void *>(&cls);
//    struct ClsPubl *p = static_cast<ClsPubl *>(objBr);
//    return p->d;
//    return *((double *)&cls+1);
    return *(double*)((char*)(&cls) + sizeof(double));
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    void *objBr = static_cast<void *>(&cls);
    struct ClsPubl *p = static_cast<ClsPubl *>(objBr);
    return p->i;
}

int main() {
    Cls obj('r', 12.2,7);

    printf("\n %c", get_c(obj));
    printf("\n %i", get_i(obj));
    printf("\n %f", get_d(obj));
}

int oldmain() {
//    Cls obj(7,  15.1,'r');
//    Cls *p = &obj;
//    printf(" \ncls %c", p);
//    printf(" \ncls %c", obj.c);
//    printf(" \ncls %s", *((int *) (p + 1)));
//
//    char * c = &obj.c;
//    double * d = &obj.d;
//    int * i = &obj.i;
//    printf(" \nc %p", c);
//    printf(" \nd %p", d);
//    printf(" \ni %p", i);
//
//    int doubleSize = sizeof(double);
//    int charSize = sizeof(char);
//    int intSize = sizeof(int);
//    printf(" \ndoubleSize %d", doubleSize);
//    printf(" \ncharSize %d", charSize);
//    printf(" \nintSize %d", intSize);


//    char str[] = "aeoc";
//    char *p2 = str;
//    printf("\nstr1 %c\n", *p2);




//    char hell[] = {0x46, 0x65, 0x6C, 0x6C};
//    printf("Hell = 0x%X\n", *((int *) hell));
//    printf("Hell = 0x%X\n", *(hell + 2));

//    char hell1[] = {'d', 'e', 'c', 'c'};
//    printf("Hell1 = 0x%X\n", *((int *) hell1));
//    printf("Hell1 = 0x%X\n", *(hell1 + 2));

//    std::cout << hell << std::endl;
//
//    Cls cl('A', 3.14, 10);
//
//    printf("%p\n", &cl);
//    int p = &cl;
//    std::cout << "-->" << *p << "<--";
};