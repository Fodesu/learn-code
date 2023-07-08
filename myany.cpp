#include <iostream>


class Any{
  struct base{

  };
  template<typename T>
  struct Data : public base{
    T data;
    Data(const T& data_) : data(data_) {} 
  };
  base* ptr;
public:
  template<typename T>
  Any(const T& t) : ptr(new Data<T>(t)) {}
};


int main() {

Any a(1);
a = 12.123;
a = "1234";

}
