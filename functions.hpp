#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "balanced_move.hpp"
#include <iostream>

List<int>* create_list(int* arr, size_t n) {
    if (n == 0) return nullptr;
    List<int>* head = new List<int>{arr[0], nullptr};
    List<int>* curr = head;
    for (size_t i = 1; i < n; i++) {
        curr->next = new List<int>{arr[i], nullptr};
        curr = curr->next;
    }
    return head;
}

void print_list(List<int>* lst) {
    while (lst) {
        std::cout << lst->val << " ";
        lst = lst->next;
    }
}

size_t list_length(List<int>* lst) {
    size_t len = 0;
    while (lst) {
        len++;
        lst = lst->next;
    }
    return len;
}

#endif
