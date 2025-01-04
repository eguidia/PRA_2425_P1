#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Método para insertar
    void insert(int pos, const T& data) {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* newNode = new Node<T>(data);
        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
        n++;
    }

    // Método para eliminar
    T remove(int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* aux = first;
        T data;
        if (pos == 0) {
            first = first->next;
            data = aux->data;
            delete aux;
        } else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < pos; i++) {
                prev = aux;
                aux = aux->next;
            }
            prev->next = aux->next;
            data = aux->data;
            delete aux;
        }
        n--;
        return data;
    }

    // Método para obtener el tamaño
    int size() const {
        return n;
    }

    // Método para verificar si está vacía
    bool empty() const {
        return n == 0;
    }

    // Método para obtener un elemento en una posición específica
    T get(int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Método para buscar un elemento
    int search(const T& data) const {
        Node<T>* aux = first;
        int index = 0;
        while (aux != nullptr) {
            if (aux->data == data) {
                return index;
            }
            aux = aux->next;
            index++;
        }
        return -1;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[ ";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data << " ";
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};

#endif

