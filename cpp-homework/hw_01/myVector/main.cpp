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
      

      ~Vector()
      {
        delete[] arr;
      }

private:
    int* arr;
    int capacity;
    int len;
}; 

int main()
{

}