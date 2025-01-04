#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                  // Puntero al array
    int max;                 // Capacidad del array
    int n;                   // Número de elementos en la lista
    static const int MINSIZE = 2;  // Tamaño mínimo

public:
    // Constructor sin argumentos
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Sobrecarga del operador []
    T operator[](int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    // Método insert()
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        if (n == max) resize(max * 2);  // Redimensionar si es necesario
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        ++n;
    }

    // Método append()
    void append(T e) override {
        insert(n, e);
    }

    // Método prepend()
    void prepend(T e) override {
        insert(0, e);
    }

    // Método remove()
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n <= max / 4 && max > MINSIZE) resize(max / 2);
        return removed;
    }

    // Método get()
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    // Método search()
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    // Método empty()
    bool empty() override {
        return n == 0;
    }

    // Método size()
    int size() override {
        return n;
    }

    // Método para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) out << " ";
        }
        out << "]";
        return out;
    }
};

#endif

