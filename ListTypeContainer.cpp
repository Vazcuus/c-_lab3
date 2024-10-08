#include "lib.h"
#include "Node.h"
#include "ListTypeContainer.h"
#include "iterator.h"
#include <iostream>
#include <iomanip>
int main (int, char **) 
{
    ListTypeContainer cont;
    ListTypeContainer cont2;
    for (auto i = 0; i < 10; i++)
    {
        cont.add_back(i);
    }
    std::cout << std::setw(30) <<"Added 0...9: ";
    cont.print();
    std::cout <<  std::setw(30) << "Size: " <<cont.size() << std::endl;
    for (auto i = 3; i <= 5; i+=1)
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
    std::cout << std::setw(30) <<"operator* index = 2 : ";
    std::cout << *(cont.begin()+2) << std::endl;
    std::cout << std::setw(30) << "operator= : ";
    cont2 = cont;
    cont2.print();
    std::cout << std::setw(30) <<"operator* index = 4: "  << *(cont+4) << std::endl;
    std::cout << std::setw(30) <<"operator[] index = 2 : "  << cont[2] << std::endl;
}
 