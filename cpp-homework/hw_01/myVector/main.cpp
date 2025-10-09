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

     Vector& operator=(Vector _arr)
    {
        swap(_arr);
        return *this;
    }

    bool push_back_v(int num)
    {
      if(capacity == len)
      {
        if(!resize_v()) return false;
        arr[len] = num;
        len++;
        return true;
      }
      else
      {
        arr[len] = num;
        len++;
        return true;
      }
    }

    bool pop_back_v()
    {
      if(len == 0) return false;
      len--;
      return true;
    }

    int getCapacity() const
    {
      return capacity;
    }

    bool insert_v(size_t index, int num)
    {
      if(index >= len) return push_back_v(num);
      else
      {
        if(capacity == len)
        {
          if(!resize_v()) return false;
        }
        len++;
        int buf=arr[index];
        arr[index] = num;
        for(size_t i=index+1; i<len; i++)
        {
          int buf2 = arr[i];
          arr[i] = buf;
          buf =buf2;
        }
      }
      return true;
    }

    bool insert_v(size_t index, const Vector& vec)
    {
      for(size_t i=0; i<vec.len; i++)
      {
        insert_v(index, vec.arr[i]);
      }
      return true;
    }

    int operator[](int index)
    {
      return arr[index];
    }

    bool erase_v(int index)
    {
      if(index > len || index < 0)
      {
        return false;
      }
      else
      {
        for(int i=index; i<len-1; i++)
        {
          arr[i] = arr[i+1];
        }
        len--;
      }
      return true;
    }

    bool erase_v(int start, int stop)
    {
      if(start >len || start < 0 || start > stop) return false;
      if(stop > len)
      {
        len = start;
        return true;
      }
      else
      {
        int i=stop-start+1;
        while (i)
        {
          erase_v(start);
          i--;
        }
      }
      return true;
    }

private:

    bool resize_v()
    {
      capacity=1.5*(capacity) ;
      int* new_arr = new int[capacity];
      if(!new_arr) return false;
      std::copy(arr, arr+len, new_arr);
      std::swap(arr, new_arr);
      delete[] new_arr;
      return true;
    }

    void swap(Vector& _arr)
    {
        std::swap(capacity, _arr.capacity);
        std::swap(len, _arr.len);
        std::swap(arr, _arr.arr);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec)
    {
      for(size_t i=0; i<vec.len; i++)
      {
        os << vec.arr[i] << " ";
      }
      return os;
    }


    size_t capacity=0;
    size_t len=0;
    int* arr=nullptr;
}; 

int main()
{
  Vector v = {-1,0,1,2,3,4,5,6};
  Vector v1 = {1,2,3};
  v1 = v;
  std::cout << v1<< "\n";
  v.erase_v(3);
  std::cout << v;
}