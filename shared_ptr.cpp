#include <iostream>
#include <memory>


struct node{
    int val;
    node(int a){
        val = a;
    }
};

struct foo : public node{
    bool sexed;
    explicit foo(int a) : node(a), sexed(false) {   }
};


int main(){
    std::shared_ptr<node> tmp;
    {
        auto now = node(10);
        tmp = std::make_shared<node>(std::move(now));
    }
    std::cout << tmp->val << '\n';
    
    foo a(20);
    node b(10);
    tmp = std::make_shared<node>(std::move(a));

    std::cout << tmp->val << '\n';


}
