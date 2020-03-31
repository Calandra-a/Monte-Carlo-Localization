#pragma once
#include "particle.cpp"
template <class T>
struct node{
 T p;
 node* next;
};

template< class K>
class pVector { 
private:
    node<K>* head;
    node<K>* tail; 
    int length;  
public: 
    pVector();
    void push_back(K);
    K at(int);
    int size();
}; 
// Member Functions - - - - - - - - - - - - - - - - - - - - - -
template< class K>
pVector<K>::pVector(){ 
    head = nullptr;
    tail = nullptr;
    length = 0;
} 
template< class K>
void pVector<K>::push_back(K p){ 
    //first object case
    if (length == 0){
        node<K> *n = new node<K>{p,nullptr};
        head = n;
        tail = n;
        n = nullptr;
        length++;
    }
    //2nd+ object case
    else{
        node<K>* n = new node<K>{p,nullptr};
        tail->next = n;
        tail = n;
        length++;
    }
} 

template< class K>
K pVector<K>::at(int index){ 
    node <K>*n = head;
    for (int i =0; i < index; i++){
        n = n->next;
    }
    return n->p;
}   
template< class K>
int pVector<K>::size(){ 
    return length; 
} 