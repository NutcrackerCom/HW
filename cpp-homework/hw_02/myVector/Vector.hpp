#include "Vector.h"

template <class T>
bool Vector<T>::push_back(T num)
{
    if(capacity == len)
      {
        if(!resize()) return false;
      }
      arr[len] = num;
      len++;
      return true;
}

template <class T>
bool Vector<T>::pop_back()
{
    if(len == 0) return false;
    len--;
    return true;
}

template <class T>
bool Vector<T>::insert(size_t index, T num)
{
    if(index >= len) return push_back(num);
    else
    {
      if(capacity == len)
      {
        if(!resize()) return false;
      }
      len++;
      T buf=arr[index];
      arr[index] = num;
      for(size_t i=index+1; i<len; i++)
      {
        std::swap(arr[i], buf);
      }
    }
    return true;
}

template <class T>
bool Vector<T>::insert(size_t index, const Vector& vec)
{
    int new_capacity = static_cast<size_t>(koef_expansion*(capacity+vec.len));
    T* new_arr = new T[new_capacity];
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

template <class T>
bool Vector<T>::erase(size_t index)
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

template <class T>
bool Vector<T>::erase(size_t start, size_t stop)
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
        T* new_arr = new T[new_capacity];
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

template <class T>
T& Vector<T>::operator[](size_t index)
{
    return arr[index];
}

template <class T>
const T& Vector<T>::operator[](size_t index) const
{
    return arr[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& _arr)
{
    if(_arr == *this) return *this;
    Vector c_arr(_arr);
    swap(c_arr);
    return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector& _arr) const
{
    if(len != _arr.len) return false;
    for(size_t i=0; i<len; i++)
    {
      if(arr[i]!=_arr.arr[i]) return false;
    }
    return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector& _arr) const
{
  return !(*this == _arr);
}

template<class U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
{
  for(size_t i=0; i<vec.len; i++)
  {
    os << vec.arr[i] << " ";
  }
  return os;
}

template <class T>
bool Vector<T>::resize(size_t n)
{
    capacity=static_cast<size_t>(koef_expansion*(capacity+n));
    T* new_arr = new T[capacity];
    if(!new_arr) return false;
    std::copy(arr, arr+len, new_arr);
    std::swap(arr, new_arr);
    delete[] new_arr;
    return true;
}

template <class T>
void Vector<T>::swap(Vector<T>& _arr)
{
    std::swap(capacity, _arr.capacity);
    std::swap(len, _arr.len);
    std::swap(arr, _arr.arr);
}