#include <iostream> 

void swap (int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int * rotate(int a[], unsigned size, int shift) {
	while(shift > 0) {
		for (int i = 0; i < size; ++i) {
			if (i != size - 1) {
				swap(&a[i], &a[i + 1]);
			}
		
		}
		
		shift--;	
	}

	return a;
}


int main() {

	int length = 10;
	int m[10] = {1,2,3,4,5,6};
	int steps = 3;

	int * res = 0;

	res = rotate(m, length, steps);

	for (int i = 0; i < 10; ++i) {
		std::cout << res[i] << ' ';
	}


	// int m[10] = {1,2,3,4,5,6};
	// int first = 0;

	// for (int i = 0; i < 10; ++i) {
	// 	if (i != 9) {
	// 		swap(&m[i], &m[i + 1]);
	// 	}
	
	// }

	// for (int i = 0; i < 10; ++i) {
	// 	std::cout << m[i] << ' ';
	// }

	// std::cout << std::endl;

	// int k = 3; 
	// int * p = 0;

	// std::cout << k << std::endl;

	// p = &k;
	// *p = 10; 

	// std::cout << k << std::endl;

}