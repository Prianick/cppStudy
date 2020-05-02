#include <iostream>

struct ivector3d {
    int array[3];
};

void scale(ivector3d *v, int k) {
    for (int i = 0; i != 3; ++i)
        v->array[i] *= k;
}

int main() {
    int arr[3] = {1, 1, 1};

    ivector3d iv3d = {{1, 1, 1}};

    scale(&iv3d, 2);
    int sum = 0;

    for (int i = 0; i != 3; ++i) {
        sum += iv3d.array[i];
    }


    std::cout << sum;
}