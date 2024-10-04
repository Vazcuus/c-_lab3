#include "lib.h"
#include "Node.h"
#include "SequenceContainer.h"
#include "iterator.h"
#include <iostream>

int main (int, char **) 
{
    SequenceContainer cont;
    cont.add_back(0);
    cont.add_back(1);
    cont.add_back(2);
    cont.add_back(3);
    cont.add_back(4);
    cont.add_back(5);
    cont.add_back(6);
    cont.add_back(7);
    cont.add_back(8);
    cont.add_back(9);
    cont.print();
    cont.size();
    cont.liquidate(3);
    cont.liquidate(5);
    cont.liquidate(7);
    cont.print();
    cont.size();
    cont.add_front(10);
    cont.print();
    cont.size();
}
 