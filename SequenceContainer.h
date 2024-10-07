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
        // SequenceContainer& operator=(const SequenceContainer &swap)
        // {
        //     data = swap.data;
        //     return *this;
        // }
        SequenceContainer(size_t _N = 10)
        {
            N = _N;
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
            size_t newN = 2*N;
            T *newCont = new T[newN];
            memcpy(newCont, data, N*sizeof(T));
            N = newN;
            delete[] data;
            data = newCont;
        }
        void insert(int value, int index)
        {
            T *temp = new T[N+1];
            N = N+1;
            size_t shift = 0;
            for (size_t i = 0; i < N+1; i++)
            {
                if (i != index)
                    temp[i] = data[i-shift];
                else
                {
                    temp[i] = value;
                    shift++;
                }
            }
            delete []data;
            data = temp;
            realsizem++;
            
        }
        void liquidate(int index)
        {
            realsizem--;
            T *temp = new int[N-1];
            N = N-1;
            size_t shift = 0;
            for (size_t i = 0; i < N; i++)
            {
                if (i+deleted != index-1)
                    temp[i] = data[i+shift];
                else
                {
                    temp[i] = data[i+1];
                    shift = 1;
                }
            }
            delete []data;
            deleted++;
            data = temp;
            
        }
        size_t realsize()
        {
            return realsizem;
        }
        size_t maxsize()
        {
            return N;
        }
        void push_back(const T &value)
        {
            if (realsizem == maxsize())
            {
                resize();
            }
            data[realsize()] = value;
            realsizem++;
        }
        void print()
        {
            for (auto i = 0; i < realsize(); i++)
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
        T *data = new int[N]{};
        size_t realsizem = 0;
};