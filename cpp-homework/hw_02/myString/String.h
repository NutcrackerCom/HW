#pragma once

#include <iostream>
#include <cstring>

class String
{
public:
    String() {}

    String(size_t n, char c): capacity(1.5*n)
                            , len(n)
                            , str(new char[capacity])
    {
        std::fill(str, str+n, c);
        str[n] = '\0';
    }

    String(const char* _str): capacity(1.5*strlen(_str))
                            , len(strlen(_str))
                            , str(new char[capacity])
    {
        strcpy(str, _str);
    }

    String(const String& _str): String(_str.len, '\0')
    {
        std::copy(_str.str, _str.str + _str.len, str);
        str[len] = '\0';
    }

    String(std::initializer_list<char> lst)
          : capacity(1.5*lst.size())
          , len(lst.size())
          , str(new char[capacity])
    {
      std::copy(lst.begin(), lst.end(), str);  
      str[len] = '\0';
    }

    ~String()
    {
        delete[] str;
    }

    String copy(size_t index, size_t len_to_cp);

    String& operator=(String _str);

    String& operator+=(const String& other);

    friend String operator+(const String& lstr, const String& rstr);

private:
    void swap(String& _str);

    friend std::ostream& operator<<(std::ostream& ss, const String& str);

    size_t capacity=0;
    size_t len=0;
    char* str=nullptr;
};