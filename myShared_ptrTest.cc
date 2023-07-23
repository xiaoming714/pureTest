#include <iostream>

#include "myShared_ptr.h"

using namespace std;

int main() {
    myShared_ptr<int> q;
    myShared_ptr<int> p(new int(1));
    cout << p.use_count() << endl;
    myShared_ptr<int> p1 = p;
    cout << p1.use_count() << endl;
    q = p1;
    cout << q.use_count() << endl;

    return 0;
}