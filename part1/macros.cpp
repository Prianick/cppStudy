#include <iostream>

int main() {

	#define MAX(x, y, r) {typeof(x) _x = x; typeof(y) _y = y; r = (_x > _y ? _x : _y);}
	#define MAX(x, y, r) ({typeof(x) _x = x; typeof(y) _y = y; r = (_x > _y ? _x : _y);})

	int x = 10;
	int y = 11;
	int r;

	MAX(x,y,r);
	

	std::cout << r;

	return 0;
}