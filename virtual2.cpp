#include <iostream>
struct Base{
  virtual void f()
  { 
    std::cout << "基类\n";
  }	
};

struct Derived : public Base{
  void f() override
  {
    std::cout << "派生";
  }
};

int main() {
  Base b;
  Derived d;

  b.f();
}



