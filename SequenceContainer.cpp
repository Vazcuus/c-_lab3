#include "lib.h"
#include <iostream>
#include "SequenceContainer.h"
#include <iomanip>
int main()
{
    SequenceContainer<int> cont;
    for (size_t i = 0; i < cont.maxsize(); ++i)
    {
        cont.push_back(i);
    }
    std::cout << std::setw(30) <<"Added 0...9: ";
    cont.print();
    for (auto i = 3; i <= 7; i+=2)
    {
        cont.liquidate(i);
    }
    std::cout << std::setw(30) <<"Liquidate 3, 5, 7: ";
    cont.print();
    cont.insert(10, 0);
    std::cout << std::setw(30) <<"Insert 10 begin:   ";
    cont.print();
    cont.insert(20, cont.realsize()/2 - (cont.realsize()%2));
    std::cout << std::setw(30) <<"Insert 20 middle:  ";
    cont.print();
    // std::cout << cont.maxsize() << " " << cont.realsize();
    cont.insert(10, 0);
    std::cout << std::setw(30) <<"Insert 10 begin:   ";
    cont.print();
    cont.insert(10, 0);
    std::cout << std::setw(30) <<"Insert 10 begin:   ";
    cont.print();
//     cont.push_back(30);
//     std::cout << std::setw(30) <<"Insert 30 end:     ";
//     cont.print();
}