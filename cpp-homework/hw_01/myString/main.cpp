#include <iostream>
#include <cstring>

class String
{
public:
    String() {}

    String(size_t n, char c): capacity(n)
                            , len(n)
                            , str(new char[n])
    {
        std::fill(str, str+n, c);
    }

    String(const char* _str): capacity(strlen(_str))
                            , len(strlen(_str))
                            , str(new char[len+1])
    {
        strcpy(str, _str);
    }

    String(const String& _str): String(_str.len, '\0')
    {
        std::memcpy(str, _str.str, len);
    }

    // что такое initializer_list ?
    String(std::initializer_list<char> lst)
          : capacity(lst.size())
          , len(lst.size())
          , str(new char[lst.size()])
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
        std::swap(capacity, _str.capacity);
        std::swap(len, _str.len);
        std::swap(str, _str.str);
    }

    friend std::ostream& operator<<(std::ostream& ss, const String& str)
    {
        ss << (str.str ? str.str : "");
        return ss;
    }

    size_t capacity=0;
    size_t len=0;
    char* str=nullptr;
};

int main()
{
    String s = "Hello";
    std::cout << s;
}