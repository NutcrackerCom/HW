#include <iostream>

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

    // что такое initializer_list ?
    String(std::initializer_list<char> lst)
          : str(new char[lst.size()])
          , capacity(lst.size())
          , len(lst.size())
    {
      std::copy(lst.begin(), lst.end(), str);  
    }

private:
    char* str;
    size_t capacity;
    size_t len;
};

int main()
{

}