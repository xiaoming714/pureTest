#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

class f {
public:
    f() { std::cout << "父类构造" << std::endl; }
    ~f() { std::cout << "父类析构" << std::endl; }
};
class s : f {
public:
    s() { std::cout << "子类构造" << std::endl; }
    void fun() { delete this; }
    ~s() { std::cout << "子类析构" << std::endl; }
};

int main() {
    int i = 0;
    // printf("%d, %d", i, i++); 测试printf参数的处理顺序
    srand(time(NULL));
    i = rand();
    printf("%d\n", i);
    s* sp = new s();
    sp->fun();
    delete sp;
    return 0;
}