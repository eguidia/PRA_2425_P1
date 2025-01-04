#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
public:
    virtual void insert(int pos, T e) = 0; // Método insert
    virtual void append(T e) = 0;          // Método append
    virtual void prepend(T e) = 0;         // Método prepend
    virtual T remove(int pos) = 0;         // Método remove
    virtual T get(int pos) = 0;            // Método get
    virtual int search(T e) = 0;           // Método search
    virtual bool empty() = 0;              // Método empty
    virtual int size() = 0;                // Método size

    virtual ~List() {} // Destructor virtual
};

#endif

