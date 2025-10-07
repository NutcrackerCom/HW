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
    }

    String(std::initializer_list<char> lst)
          : capacity(1.5*lst.size())
          , len(lst.size())
          , str(new char[capacity])
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

    String& operator+=(const String& other)
    {
        capacity = 1.5*(len+other.len);
        char* new_str = new char[capacity];
        if(!new_str) return *this;
        strcpy(new_str, str);
        strcat(new_str, other.str);
        strcpy(str, new_str);
        len+=other.len;
        delete[] new_str;
        return *this;
    }

    friend String operator+(const String& lstr, const String& rstr)
    {
        String res(lstr);
        res+=rstr;
        return res;
    }

    String copy_s(int index, int len_to_cp)
    {
        if(index >= len) return String();
        if(index+len_to_cp>len) len_to_cp=len-index;

        String res(len_to_cp, '\0');
        std::copy(str+index, str+index+len_to_cp, res.str);
        return res;
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
    String s2 = " world";
    s +=s2;
    String s3 = s;
    String s4 = s.copy_s(5, 3);
    std::cout << s4;
}