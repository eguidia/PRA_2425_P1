#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
public:
    virtual void insert(int pos, const T& value) = 0;
    virtual T remove(int pos) = 0;
    virtual T get(int pos) const = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual int search(const T& value) const = 0;
    virtual ~List() {}
};

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size);

public:
    ListArray();
    ~ListArray();

    void insert(int pos, const T& value) override;
    T remove(int pos) override;
    T get(int pos) const override;
    int size() const override;
    bool empty() const override;
    int search(const T& value) const override;
    
    void append(const T& value);   // Añadir al final
    void prepend(const T& value);  // Añadir al principio

    T operator[](int pos);

    // Definición de operator<< como plantilla
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
};

template <typename T>
ListArray<T>::ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    T* new_arr = new T[new_size];
    for (int i = 0; i < n; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    max = new_size;
}

template <typename T>
void ListArray<T>::insert(int pos, const T& value) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posición inválida!");
    }
    
    if (n == max) {
        resize(max * 2);
    }

    for (int i = n; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    ++n;
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }

    T removed_value = arr[pos];
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;

    if (n <= max / 4 && max > MINSIZE) {
        resize(max / 2);
    }

    return removed_value;
}

template <typename T>
T ListArray<T>::get(int pos) const {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }
    return arr[pos];
}

template <typename T>
int ListArray<T>::size() const {
    return n;
}

template <typename T>
bool ListArray<T>::empty() const {
    return n == 0;
}

template <typename T>
int ListArray<T>::search(const T& value) const {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void ListArray<T>::append(const T& value) {
    insert(n, value);  // Usamos insert para agregar al final
}

template <typename T>
void ListArray<T>::prepend(const T& value) {
    insert(0, value);  // Usamos insert para agregar al principio
}

template <typename T>
T ListArray<T>::operator[](int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición inválida!");
    }
    return arr[pos];
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
    out << "[";
    for (int i = 0; i < list.size(); ++i) {
        out << list.arr[i];
        if (i < list.size() - 1) {
            out << " ";
        }
    }
    out << "]";
    return out;
}

#endif // LISTARRAY_H

