#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
class Node {
private:
    T* data;
    Node* next;
    Node* before;

public:
    Node() {
        data = NULL;
        next = NULL;
        before = NULL;
    }

    Node(T* pData) {
        this->data = pData;
        this->next = NULL;
        this->before = NULL;
    }

    T* getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }

    Node* getBefore() {
        return before;
    }
    
    void setBefore(Node* pValue) {
        if (pValue != NULL) {
            this->before = pValue;
        }
        
    }

    void setNext(Node* pValue) {
        this->next = pValue;

    }
};

#endif