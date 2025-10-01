#include <iostream>

class Vector
{
public:

    Vector()
    {
      arr = new int[1];
      capacity = 1;
      len = 0;
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

    ~Vector()
    {
      delete[] arr;
    }

private:
    int* arr;
    size_t capacity;
    size_t len;
}; 

int main()
{

}