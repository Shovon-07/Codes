#include <iostream>
// #include "header/stack.h"
// #include "header/circulerQueue.h"
// #include "header/recursion.h"
// #include "header/matrix.h"
// #include "header/tree/tree.h"
#include "header/tree/bst.h"
using namespace std;

int main()
{
    bst t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    t.traverse();
    t.search(10);

    return 0;
}
