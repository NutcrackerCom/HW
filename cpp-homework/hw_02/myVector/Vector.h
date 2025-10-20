#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdexcept>
#define koef_expansion 1.5

template <class T>
class Vector
{
public:
    Vector()
    {
      arr = new T[1];
      capacity = 1;
      len = 0;
    }

    Vector(const Vector<T>& _arr): Vector(_arr.len, 0)
    {
        std::copy(_arr.arr, _arr.arr + _arr.len, arr);
    }

    Vector(size_t n, T num): capacity(static_cast<size_t>(koef_expansion*n))
                             , len(n)
                             , arr(new T[capacity])
    {
        std::fill(arr, arr+n, num);
    }
      
    Vector(std::initializer_list<T> lst): capacity(static_cast<size_t>(koef_expansion*lst.size()))
                                          , len(lst.size())
                                          , arr(new T[capacity])
    {
      size_t i=0;
      for(T num: lst)
      {
        arr[i]=num;
        i++;
      }    
    }

    ~Vector()
    {
      delete[] arr;
    }

    bool push_back(T num);

    bool pop_back();

    int get_capacity() const
    {
      return capacity;
    }

    size_t get_size() const
    {
      return len;
    }

    bool insert(size_t index, T num);

    bool insert(size_t index, const Vector& vec);

    bool erase(size_t index);

    bool erase(size_t start, size_t stop);

    T& operator[](int index);

    T operator[](int index) const;

    Vector& operator=(const Vector& _arr);

    bool operator==(const Vector& _arr) const;

    bool operator!=(const Vector& _arr) const;

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
    {
    for(size_t i=0; i<vec.len; i++)
    {
        os << vec.arr[i] << " ";
    }
    return os;
    }

private:
    
    bool resize(int n=0);

    void swap(Vector<T>& _arr);

    size_t capacity=0;
    size_t len=0;
    T* arr=nullptr;
};
