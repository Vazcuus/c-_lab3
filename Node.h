#pragma once
#include <iostream>
class Node 
{
    friend class ListTypeContainer;
    friend class iterator;

    public:
        Node *next;
        Node *prev;
        int value;

        void print_val() {std::cout << value << " ";}
        Node(int _value): value(_value) {};
        Node(){};
        ~Node(){};

};