#include "Vector.h"

bool Vector::push_back(int num)
{
    if(capacity == len)
      {
        if(!resize()) return false;
      }
      arr[len] = num;
      len++;
      return true;
}

bool Vector::pop_back()
{
    if(len == 0) return false;
    len--;
    return true;
}

int Vector::get_capacity() const
{
    return capacity;
}

int Vector::get_size() const
{
    return len;
}

bool Vector::insert(size_t index, int num)
{
    if(index >= len) return push_back(num);
    else
    {
      if(capacity == len)
      {
        if(!resize()) return false;
      }
      len++;
      for(size_t i=index; i<len; i++)
      {
        std::swap(arr[i], num);
      }
    }
    return true;
}

bool Vector::insert(size_t index, const Vector& vec)
{
    int new_capacity = static_cast<size_t>(koef_expansion*(static_cast<float>(capacity)+vec.len));
    int* new_arr = new int[new_capacity];
    for(size_t i=0; i<index;i++)
    {
      new_arr[i]=arr[i];
    }
    for(size_t i=0; i<vec.len;i++)
    {
      new_arr[index+i]=vec.arr[i];
    }
    for(size_t i=index; i<len; i++)
    {
      new_arr[i+vec.len]=arr[i];
    }
    delete [] arr;
    arr = new_arr;
    capacity = new_capacity;
    len += vec.len;
    return true;
}

bool Vector::erase(size_t index)
{
    if(index > len)
      {
        return false;
      }
      else
      {
        for(size_t i=index; i<len-1; i++)
        {
          arr[i] = arr[i+1];
        }
        len--;
      }
      return true;
}

bool Vector::erase(size_t start, size_t stop)
{
    if(start >len || start > stop) return false;
      if(stop >= len)
      {
        len = start;
        return true;
      }
      else
      {
        size_t new_capacity = static_cast<size_t>(koef_expansion*(len-(stop-start)));
        int* new_arr = new int[new_capacity];
        if(!new_arr) return false;
        size_t diff = stop-start;
        for(size_t i=0; i<start; i++)
        {
          new_arr[i]=arr[i];
        }

        for(size_t i=0; i<diff;i++)
        {
          new_arr[start+i]=arr[stop+i];
        }
        delete [] arr;
        arr = new_arr;
        capacity = new_capacity;
        len -= diff;
      }
      return true;
}
 
/*Vector Vector::for_each(int start, int stop, int(*op)(int, int))
{
  if(start >len || start < 0 || start > stop || stop > len) return *this;
  
  for(size_t i=start; i<=stop; i++)
  {
    //...
  }
}*/

int& Vector::operator[](int index)
{
    return arr[index];
}

int Vector::operator[](int index) const
{
    return arr[index];
}

Vector& Vector::operator=(const Vector& _arr)
{
    if(_arr == *this) return *this;
    Vector c_arr(_arr);
    swap(c_arr);
    return *this;
}

bool Vector::operator==(const Vector& _arr) const
{
    if(len != _arr.len) return false;
    for(size_t i=0; i<len; i++)
    {
      if(arr[i]!=_arr.arr[i]) return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& _arr) const
{
  return !(*this == _arr);
}

bool Vector::resize(int n)
{
    capacity=static_cast<size_t>(koef_expansion*(static_cast<float>(capacity)+n));
    int* new_arr = new int[capacity];
    if(!new_arr) return false;
    std::copy(arr, arr+len, new_arr);
    std::swap(arr, new_arr);
    delete[] new_arr;
    return true;
}

void Vector::swap(Vector& _arr)
{
    std::swap(capacity, _arr.capacity);
    std::swap(len, _arr.len);
    std::swap(arr, _arr.arr);
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    for(size_t i=0; i<vec.len; i++)
    {
        os << vec.arr[i] << " ";
    }
    return os;
}