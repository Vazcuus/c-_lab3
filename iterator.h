#pragma once
#include <iostream>
#include "SequenceContainer.h"
#include "Node.h"

class iterator
{
    private:
        Node *node;
    public:
        friend class SequenceContainer;

        iterator(): node(0){};
        iterator(Node *inode): node(inode){};
        iterator(const iterator &iterato): node(iterato.node){};

        bool operator!=(const iterator &itero) const
        {
            return !(itero != *this);
        }
        iterator& operator++()
        {
            if (node == 0)
            {
                throw "Empty";
            }
            if (node->next == 0)
            {
                throw "The end";
            }
            node = node->next;
            return *this;

        }

        iterator& operator--()
        {
            if (node == 0)
            {
                throw "Empty";
            }
            if (node->next == 0)
            {
                throw "The end";
            }
            node = node->prev;
            return *this;

        }

        int operator*() const
        {
            if (node == 0)
            {
                throw "Empty";
            }
            return node->value;
        }

};