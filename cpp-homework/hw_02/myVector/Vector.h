#pragma once

#include <iostream>
#include <cstring>

class Vector
{
public:
    Vector()
    {
      arr = new int[1];
      capacity = 1;
      len = 0;
    }

    Vector(const Vector& _arr): Vector(_arr.len, 0)
    {
        std::copy(_arr.arr, _arr.arr + _arr.len, arr);
    }

    Vector(size_t n, int num): capacity(1.5*n)
                             , len(n)
                             , arr(new int[capacity])
    {
        std::fill(arr, arr+n, num);
    }
      
    Vector(std::initializer_list<int> lst): capacity(1.5*lst.size())
                                          , len(lst.size())
                                          , arr(new int[capacity])
    {
      size_t i=0;
      for(auto num: lst)
      {
        arr[i]=num;
        i++;
      }    
    }

    ~Vector()
    {
      delete[] arr;
    }

    bool push_back(int num);

    bool pop_back();

    inline int get_capacity() const;

    inline int get_size() const;

    bool insert(size_t index, int num);

    bool insert(size_t index, const Vector& vec);

    bool erase(size_t index);

    bool erase(size_t start, size_t stop);

    //Vector for_each(int start, int stop, int(*op)(int, int));

    int operator[](int index);

    int operator[](int index) const;

    Vector& operator=(Vector _arr);

    bool operator==(const Vector& _arr);

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

private:
    
    bool resize();

    void swap(Vector& _arr);

    size_t capacity=0;
    size_t len=0;
    int* arr=nullptr;
};
