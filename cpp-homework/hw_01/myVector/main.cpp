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

    Vector(size_t n, int num): capacity(n)
                             , len(n)
                             , arr(new int[n])
    {
        std::fill(arr, arr+n, num);
    }
      
    Vector(std::initializer_list<int> lst): capacity(lst.size())
                                          , len(lst.size())
                                          , arr(new int[lst.size()])
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

private:

    void swap(Vector& _arr)
    {
        std::swap(capacity, _arr.capacity);
        std::swap(len, _arr.len);
        std::swap(arr, _arr.arr);
    }

    size_t capacity=0;
    size_t len=0;
    int* arr=nullptr;
}; 

int main()
{
  
}