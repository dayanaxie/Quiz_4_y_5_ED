#include "nodo.h"
#include "event.h"

#ifndef LIST 

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* last;
    int quantity;
    bool empty;
    Node<T>* searchPosition = NULL;
    Node<T>* searchBehind = NULL;

public:
    List() {
        first = NULL;
        last = NULL;
        quantity = 0;
        empty = true;
    }

    void add(T* pData) {
        Node<T>* newNode = new Node<T>(pData);

        if (quantity > 0) {
            this->last->setNext(newNode);
        }
        else {
            this->first = newNode;
        }
        newNode->setBefore(this->last);
        this->last = newNode;

        empty = false;
        quantity++;
    }

    Node<T>* getFirst() {
        return this->first;
    }

    Node<T>* getLast() {
        return this->last;
    }

    int getSize() {
        return quantity;
    }

    bool isEmpty() {
        return !quantity;
    }

    T* find(int pPosition) {
        T* result = NULL;
        searchPosition = this->first;
        searchBehind = NULL;

        if (pPosition < getSize()) {
            while (pPosition > 0) {
                searchBehind = searchPosition;
                searchPosition = searchPosition->getNext();
                pPosition--;
            }
            result = searchPosition->getData();
        }
        return result;
    }

    // es que si el position es mayor a la cantidad, entonces inserto al final
    void insert(int pPosition, T* pData) {

        if (pPosition < getSize() && first != NULL) {
            Node<T>* newNodo = new Node<T>(pData);

            T* result = find(pPosition);
            newNodo->setNext(searchPosition);

            if (searchBehind != NULL) {
                newNodo->setBefore(this->searchBehind);
                searchBehind->setNext(newNodo);
            }
            else {
                this->first->setBefore(newNodo);
                this->first = newNodo;
            }
            quantity++;
        }
        else {
            add(pData);
        }
    }

    bool remove(int pPosition) {
        bool result = false;
        if (first != NULL && pPosition < getSize()) {
            Node<T>* search = first;
            if (pPosition != 0) {
                
                T* data = find(pPosition);
                searchBehind->setNext(searchPosition->getNext());

                if (searchPosition == last) {
                    last = searchBehind;
                }
                if (searchPosition->getNext() != NULL) {
                    searchPosition->getNext()->setBefore(searchBehind);
                }
                searchPosition->setNext(NULL);
            }
            else {
                first = first->getNext();
                search->setNext(NULL);
                delete search;
            }
            quantity--;
        }
        return result;
    }
};

#endif