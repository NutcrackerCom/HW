#include "String.h"

String String::copy(int index, int len_to_cp)
{
    if(index >= len) return String();
    if(index+len_to_cp>len) len_to_cp=len-index;

    String res(len_to_cp, '\0');
    std::copy(str+index, str+index+len_to_cp, res.str);
    return res;
}

void String::swap(String& _str)
{
    std::swap(capacity, _str.capacity);
    std::swap(len, _str.len);
    std::swap(str, _str.str);
}

String& String::operator=(String _str)
{
    swap(_str);
    return *this;
}

String& String::operator+=(const String& other)
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

String operator+(const String& lstr, const String& rstr)
{
    String res(lstr);
    res+=rstr;
    return res;
}

std::ostream& operator<<(std::ostream& ss, const String& str)
{
    ss << (str.str ? str.str : "");
    return ss;
}