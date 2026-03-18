#ifndef BALANCED_MOVE_HPP
#define BALANCED_MOVE_HPP

#include <cstddef>

template <class T>
struct List {
    T val;
    List<T>* next;
};

template <class T>
struct Vec {
    T* data;
    size_t s, cap;
};

template <class T>
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k) {
    size_t total = 0;
    for (size_t i = 0; i < v.s; i++) {
        List<T>* curr = v.data[i];
        while (curr) {
            total++;
            curr = curr->next;
        }
    }
    size_t base = total / k;
    size_t extra = total % k;
    Vec< List<T>* > result;
    result.s = k;
    result.cap = k;
    result.data = new List<T>*[k]();
    size_t curr_list = 0;
    size_t needed = base + (curr_list < extra ? 1 : 0);
    size_t count = 0;
    for (size_t i = 0; i < v.s && curr_list < k; i++) {
        while (v.data[i] && curr_list < k) {
            List<T>* node = v.data[i];
            v.data[i] = node->next;
            node->next = nullptr;
            if (!result.data[curr_list]) {
                result.data[curr_list] = node;
            } else {
                List<T>* tail = result.data[curr_list];
                while (tail->next)
                    tail = tail->next;
                tail->next = node;
            }
            count++;
            if (count >= needed) {
                curr_list++;
                if (curr_list < k) {
                    needed = base + (curr_list < extra ? 1 : 0);
                    count = 0;
                }
            }
        }
    }
    return result;
}

#endif
