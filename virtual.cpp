#include <iostream>

// 为什么需要virtual 继承？
// 避免菱形继承时发生浪费

struct B{ int n;};
struct C : virtual public B {};
struct D : virtual public B {};
struct E : public B {};


struct A : public C, public D, public E {
  void f() {
    C::n = 1;
    D::n = 2;
    E::n = 3;
    std::cout << C::n << " " << D::n << " " << E::n << '\n';
  } 
};

int main() {
A a;
a.f();
	
}
