#pragma once
#include "particle.cpp"

struct node{
 particle p;
 node* next;
};

class pVector { 
private:
    node* head;
    node* tail; 
    int length;  
public: 
    pVector();
    void push_back(particle);
    particle at(int);
    int size();
}; 
// Member Functions - - - - - - - - - - - - - - - - - - - - - -
pVector::pVector(){ 
    head = nullptr;
    tail = nullptr;
    length = 0;
} 

void pVector::push_back(particle p){ 
    //first object case
    if (length == 0){
        node *n = new node{p,nullptr};
        head = n;
        tail = n;
        n = nullptr;
        length++;
    }
    //2nd+ object case
    else{
        node *n = new node{p,nullptr};
        tail->next = n;
        tail = n;
        length++;
    }
} 
  
particle pVector::at(int index){ 
    node *n = head;
    for (int i =0; i < index; i++){
        n = n->next;
    }
    return n->p;
}   

int pVector::size(){ 
    return length; 
} 