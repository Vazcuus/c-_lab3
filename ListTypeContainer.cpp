#include "lib.h"
#include "Node.h"
#include "ListTypeContainer.h"
#include "iterator.h"
#include <iostream>
#include <iomanip>
int main (int, char **) 
{
    ListTypeContainer cont;
    for (auto i = 0; i < 10; i++)
    {
        cont.add_back(i);
    }
    std::cout << std::setw(30) <<"Added 0...9: ";
    cont.print();
    std::cout <<  "Size: " <<cont.size() << std::endl;
    for (auto i = 3; i <= 7; i+=2)
    {
        cont.liquidate(i);
    }
    std::cout << std::setw(30) <<"Liquidate 3, 5, 7: ";
    cont.print();
    std::cout << std::setw(30) << "Size: " <<cont.size() << std::endl;
    cont.add_front(10);
    std::cout << std::setw(30) <<"Insert 10 begin:   ";
    cont.print();
    std::cout <<  std::setw(30) << "Size: " <<cont.size() << std::endl;
    cont.insert(20, cont.size()/2 - (cont.size()%2));
    std::cout << std::setw(30) <<"Insert 20 middle:  ";
    cont.print();
    std::cout <<  std::setw(30) << "Size: " <<cont.size() << std::endl;
    cont.add_back(30);
    std::cout << std::setw(30) <<"Insert 30 end:     ";
    cont.print();
    std::cout <<  std::setw(30) << "Size: " <<cont.size() << std::endl;
    cont.insert(99, 2);
    std::cout << std::setw(30) <<"Insert test: ";
    cont.print();
    std::cout <<  std::setw(30) << "Size: " <<cont.size() << std::endl;
    std::cout << std::setw(30) <<"operator* : ";
    cont.print();
    std::cout << *(cont.begin()+2);
}
 