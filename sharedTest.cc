#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int *i = new int(1);
    shared_ptr<int> sp1(i);
    // 用一个原始指针初始化两个不同的shared_ptr会造成重复释放的问题
    shared_ptr<int> sp2(i);
    return 0;
}