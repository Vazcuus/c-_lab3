#include <iostream>
#include <array>
#include <algorithm>
template <typename T>
class SequenceContainer 
{
    public:
        size_t N;
        int deleted = 0;
        T operator[](int index)
        {
            return data[index];
        }
        SequenceContainer& operator=(const SequenceContainer &swap)
        {
            delete[] data;
            data = swap.data;
            return *this;
        }
        SequenceContainer(size_t _N = 10)
        {
            N = _N+1;
        }
        test()
        {
            return *data;
        }
        SequenceContainer(const SequenceContainer<T> &other)
        {
            for (size_t i = 0; i < N; ++i)
            {
                    data[i] = other.data[i];
            }
        }
        CopyArr(size_t N)
        {

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
                if (i+deleted != index)
                    data[i] = data[i+shift];
                else
                {
                    data[i] = data[i+1];
                    shift = 1;
                }
            }
            deleted++;
            
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