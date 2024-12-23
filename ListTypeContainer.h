#pragma once
#include <iostream>
#include "Node.h"
#include "iterator.h"

class ListTypeContainer 
{
    private:
        Node *head;
        Node *tail;

        iterator head_it;
        iterator tail_it;

    public:
        friend class Node;
        friend class iterator;
        iterator begin() {return head_it;}
        iterator end() {return tail_it;}

        int size()
        {
            int counter = 0;
            for (iterator start = head_it; start.node != tail_it.node; ++start)
            {
                ++counter;
            }
            return counter;

        }
        int operator[](int index)
        {
            return *(head_it+index);
        }

        int operator*()
        {
            return *(head_it);
        }
        
        iterator operator+(int value)
        {
            iterator temp = head_it;
            for (auto i = 0; i < value; i++)
            {
                temp.node = temp.node->next;
            }
            return temp;
        }
        ListTypeContainer(ListTypeContainer && moved)
        {
            head = moved.head;
            tail = moved.tail;
            head_it = moved.head_it;
            tail_it = moved.tail_it;
    
            delete moved.head;
            delete moved.tail;
        }

        ListTypeContainer()
        {
            head = tail = new Node;
            tail->next = nullptr;
            tail->prev = nullptr;

            head_it = iterator(head);
            tail_it = iterator(tail);
        }
        ListTypeContainer& operator=(const ListTypeContainer& copy)
        {
            head = tail = new Node;
            iterator current = copy.head_it;

            for (iterator start = current; start.node != copy.tail_it.node; start++)
            {
                add_back(start.node->value);
            }
            return *this;
        }

        ~ListTypeContainer()
        {
            Node *to_delete = head;
            for (Node *start = head; start != tail;)
            {
                start = start->next;
                delete to_delete;
                to_delete = start;
            }
            delete to_delete;
        }

        void add_front(int value)
        {
            Node *to_add = new Node(value);
            to_add->next = head;
            to_add->prev = nullptr;
            head->prev = to_add;
            head = to_add;
            head_it = iterator(head);
        }
        void add_back(int value)
        {
            if (isempty())
            {
                add_front(value);
            }
            else
            {
                Node *to_add = new Node(value);
                to_add->next = tail;
                to_add->prev = tail->prev;
                tail->prev->next = to_add;
                tail->prev = to_add;

                tail_it = iterator(tail);
            }
        }
        void insert(int value, int index)
        {
            if (isempty())
            {
                add_front(value);
            }
            else
            {
                int i = 0;
                iterator temp = iterator(head);
                while(i <= index-1)
                {
                    ++temp;
                    i++;
                }
                --temp;
                Node *to_add = new Node(value);
                to_add->prev = temp.node;
                to_add->next = temp.node->next;
                temp.node->next = to_add;
                temp.node->next->next->prev = to_add;
            }
        }
        bool liquidate(int n)
        {
            int i = 1;
            iterator temp = head_it;
            while (i != n)
            {
                ++temp;
                i++;
            }
            temp.node->prev->next = temp.node->next;
            temp.node->next->prev = temp.node->prev;
            return true;

        }
        void print() const
        {
            for (iterator start = head_it; start.node != tail_it.node; ++start)
            {
                start.node->print_val();
            }
            std::cout << std::endl;
        }
        bool isempty()
        {
            return (head == tail);
        }

};