#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>
template <typename T>
class SequenceContainer 
{
    public:
        size_t N;
        T operator[](int index)
        {
            return data[index+1];
        }
        int* operator+(int value)
        {
            return data+value+1;
        }
        T operator*()
        {
            return *(data);
        }
        SequenceContainer& operator=(const SequenceContainer &swap)
        {
            delete[] data;
            data = swap.data;
            realsizem = swap.realsizem;
            return *this;
        }
        SequenceContainer(SequenceContainer&& swap)
        {
            delete[] data;
            data = swap.data;
            realsizem = swap.realsizem;
            delete []swap.data;
        }
        SequenceContainer(size_t _N = 10)
        {
            N = _N+1;
        }
        SequenceContainer(const SequenceContainer<T> &other)
        {
            for (size_t i = 0; i < N; ++i)
            {
                    data[i] = other.data[i];
            }
        }
        void resize()
        {
            size_t newN = 2*(N-1)+1;
            T *newCont = new T[newN];
            memcpy(newCont, data, N*sizeof(T));
            N = newN;
            delete[] data;
            data = newCont;
        }
        void insert(T value, int index)
        {
            realsizem++;
            if (realsize() >= maxsize())
            {
                resize();
            }
            size_t shift = 0;
            for (size_t i = 1; i < realsize()+1; i++)
            {
                if (i == index+1)
                {
                    shift++;
                    data[0] = data[i];
                    data[i] = value;
                }
                if (i > index+1)
                    std::swap(data[i], data[0]);
            }        
        }
        void add_middle(T value)
        {
            insert(value, realsize()/2);
        }
        void liquidate(T index)
        {
            realsizem--;
            size_t shift = 0;
            for (size_t i = 0; i < N; i++)
            {
                if (i != index)
                    data[i] = data[i+shift];
                else
                {
                    data[i] = data[i+1];
                    shift = 1;
                }
            }
            
        }
        size_t realsize()
        {
            return realsizem;
        }
        size_t maxsize()
        {
            return N;
        }
        void push_back(T value)
        {
            insert(value, realsize());
        }
        void print()
        {
            for (auto i = 1; i < realsize()+1; i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
        ~SequenceContainer()
        {
            delete[] data;
        }
    private:
        T *data = new int[N+1]{};
        size_t realsizem = 0;
};