#include <foo.hpp> - библиотечные файлы
#include "foo.hpp" - локальные файлы

если main возвращает не 0, тогда считается что программа закончила выполнение с ошибкой

компиляция
- g++ file.cpp -o program
- g++ -E file.cpp -o file_preprocessed.cpp
- g++ -c file.cpp (скомпилировать объектный файл) 


Дизассемблирование
- objdump -d main.o
- objdump -x main.o (дополнительные таблицы) 
