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

    Vector(const Vector<T>& _arr) : capacity(_arr.capacity), len(_arr.len), arr(new T[capacity])
    {
        for(size_t i = 0; i < len; i++) {
            arr[i] = _arr.arr[i]; // Используем оператор присваивания, а не побитовое копирование
        }
    }

    Vector(size_t n, T num): capacity(static_cast<size_t>(koef_expansion*n))
                             , len(n)
                             , arr(new T[capacity])
    {
      for(size_t i = 0; i < n; i++) {
        arr[i] = num;
      }
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

    size_t get_capacity() const
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

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    Vector& operator=(const Vector& _arr);

    bool operator==(const Vector& _arr) const;

    bool operator!=(const Vector& _arr) const;

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

private:
    
    bool resize(size_t n=0);

    void swap(Vector<T>& _arr);

    size_t capacity=0;
    size_t len=0;
    T* arr=nullptr;
};

#include "Vector.hpp"