#include <iostream>
#include <cstring>

class String
{
public:
    String() {}

    String(size_t n, char c): str(new char[n])
                            , capacity(n)
                            , len(n)
    {
        std::fill(str, str+n, c);
    }

    String(const String& _str): String(_str.len, '\0')
    {
        std::memcpy(str, _str.str, len);
    }

    // что такое initializer_list ?
    String(std::initializer_list<char> lst)
          : str(new char[lst.size()])
          , capacity(lst.size())
          , len(lst.size())
    {
      std::copy(lst.begin(), lst.end(), str);  
    }

    String& operator=(String _str)
    {
        swap(_str);
        return *this;
    }

    ~String()
    {
        delete[] str;
    }

private:

    void swap(String& _str)
    {
        std::swap(str, _str.str);
        std::swap(len, _str.len);
        std::swap(capacity, _str.capacity);
    }

    char* str;
    size_t capacity;
    size_t len;
};

int main()
{

}