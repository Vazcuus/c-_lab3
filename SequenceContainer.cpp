#include "lib.h"
#include <iostream>
#include "SequenceContainer.h"
#include <iomanip>
#include <cstring>
int main()
{
    SequenceContainer<int> cont;
    SequenceContainer<int> cont2;
    SequenceContainer<int> cont3(SequenceContainer<int>(12));
    for (size_t i = 1; i < cont.maxsize(); ++i)
    {
        cont.push_back(i-1);
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
    cont.add_middle(20);
    std::cout << std::setw(30) <<"Insert 20 middle:  ";
    cont.print();
    cont.push_back(30);
    std::cout << std::setw(30) <<"Insert 30 end:     ";
    cont.print();
    std::cout << std::setw(30) <<"operator= :     ";
    cont2 = cont;
    cont2.print();
    std::cout << std::setw(30) <<"operator[]  index=5 :     " << cont[5] << std::endl;
    std::cout << std::setw(30) <<"operator*  index=5 :     " << *(cont+5);
}