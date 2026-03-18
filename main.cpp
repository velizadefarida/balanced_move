#include "balanced_move.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7};
    int arr3[] = {8, 9, 10, 11};

    Vec<List<int>*> v;
    v.s = 3;
    v.cap = 3;
    v.data = new List<int>*[3];
    v.data[0] = create_list(arr1, 5);
    v.data[1] = create_list(arr2, 2);
    v.data[2] = create_list(arr3, 4);

    size_t k = 4;
    Vec<List<int>*> result = balanced_move<int>(v, k);

    for (size_t i = 0; i < result.s; i++) {
        print_list(result.data[i]);
        std::cout << "\n";
    }

    for (size_t i = 0; i < result.s; i++) {
        List<int>* curr = result.data[i];
        while (curr) {
            List<int>* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    delete[] result.data;
    delete[] v.data;

    return 0;
}
