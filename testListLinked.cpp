#include <iostream>
#include "ListLinked.h"

int main() {
    ListLinked<int> l;
    std::cout << "List => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << (l.empty() ? "true" : "false") << std::endl;

    // Insertando elementos
    l.insert(0, -5);
    l.insert(1, 0);
    l.insert(2, 5);
    l.insert(3, 10);
    std::cout << "List => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << (l.empty() ? "true" : "false") << std::endl;

    // Accediendo a elementos por índice
    std::cout << "l.get(0) => " << l.get(0) << "; l[0] => " << l[0] << std::endl;
    std::cout << "l.get(3) => " << l.get(3) << "; l[3] => " << l[3] << std::endl;

    // Eliminando elementos
    std::cout << "l.remove(3) => " << l.remove(3) << std::endl;
    std::cout << "l.remove(1) => " << l.remove(1) << std::endl; 
    std::cout << "l.remove(0) => " << l.remove(0) << std::endl; 
    std::cout << "List => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << (l.empty() ? "true" : "false") << std::endl;

    // Más inserciones y verificaciones
    l.insert(0, 33);
    l.insert(1, 5);
    l.insert(2, 14);
    std::cout << "List => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << (l.empty() ? "true" : "false") << std::endl;

    // Buscando elementos
    std::cout << "l.search(14) => " << l.search(14) << std::endl;  
    std::cout << "l.search(55) => " << l.search(55) << std::endl;  

    // Probando inserciones fuera de rango
    try {
        l.insert(-1, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "l.insert(-1, 99) => " << e.what() << std::endl;
    }
    try {
        l.insert(4, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "l.insert(4, 99) => " << e.what() << std::endl;
    }

    // Probando accesos fuera de rango
    try {
        l.get(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "l.get(-1) => " << e.what() << std::endl;
    }
    try {
        l.get(3);
    } catch (const std::out_of_range& e) {
        std::cout << "l.get(3) => " << e.what() << std::endl;
    }

    // Probando eliminaciones fuera de rango
    try {
        l.remove(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "l.remove(-1) => " << e.what() << std::endl;
    }
    try {
        l.remove(3);
    } catch (const std::out_of_range& e) {
        std::cout << "l.remove(3) => " << e.what() << std::endl;
    }

    return 0;
}

