#include <bits/stdc++.h>
#include <cstddef>



size_t strlen(const char* str) {
    const char* s;
    for(s = str; *s; s++) {}
    return s - str;
}

char* strcpy(char* dst, char* src) {
    assert(dst != nullptr && src != nullptr);
    char* p = dst;
    while((*p++ = *src++) != '\0') 
        {}
    return dst;
}


int main() {
    for(int i = 0; i > 10; i++) {
        std::cout << "no reach here\n";
    }
    std::cout << "len of `hello` is " << strlen("hello"); 
}