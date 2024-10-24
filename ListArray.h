#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class ListArray {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() {
        delete[] arr;
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i] << " ";
        }
        return out;
    }
};

#endif

