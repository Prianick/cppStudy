#include <iostream>

using namespace std;

// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p) {
    int answer;
    if (p == 0) {
    	return 1;
    }
    if (x == 1) {
    	return 1;
    }
    answer = x;
    for (int i = 1; i < p; ++i) {
		answer *= x;
    }
    return answer;
}

int main () { 
	std::cout << power(-2, 5);
}