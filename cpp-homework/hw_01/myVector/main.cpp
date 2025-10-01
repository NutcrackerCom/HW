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

    Vector(const Vector& _arr): Vector(_arr.len, '\0')
    {
        std::memcpy(arr, _arr.arr, len);
    }

    Vector(size_t n, int num): arr(new int[n])
                            , capacity(n)
                            , len(n)
    {
        std::fill(arr, arr+n, num);
    }
      
    // что такое initializer_list ?
    Vector(std::initializer_list<int> lst)
          : arr(new int[lst.size()])
          , len(lst.size())
          , capacity(lst.size())
    {
      size_t i=0;
      for(auto num: lst)
      {
        arr[i]=num;
        i++;
      }    
    }

    Vector& operator=(const Vector& _arr)
    {
        if(&_arr == this) return *this;
        
        delete[] arr;
        arr = new int[_arr.capacity];
        capacity = _arr.capacity;
        len = _arr.len;
        std::memcpy(arr, _arr.arr, len);
        return *this;
    }

    ~Vector()
    {
      delete[] arr;
    }

     Vector& operator=(Vector _arr)
    {
        swap(_arr);
        return *this;
    }

    int GetLen()
    {
      return len;
    }

private:

    void swap(Vector& _arr)
    {
        std::swap(arr, _arr.arr);
        std::swap(len, _arr.len);
        std::swap(capacity, _arr.capacity);
    }

    int* arr;
    size_t capacity;
    size_t len;
}; 

int main()
{
  
}