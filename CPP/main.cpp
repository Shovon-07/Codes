#include <iostream>
#include "header/stack.h"
#include "header/circulerQueue.h"
#include "header/recursion.h"
#include "header/matrix.h"
using namespace std;

class car
{
public:
    car() { cout << "Car \n"; }
    ~car() { cout << "Destruct Car \n"; }
};
class sportsCar : public car
{

public:
    sportsCar() { cout << "Sports car\n"; }
    ~sportsCar() { cout << "Destruct Sports car\n"; }
};

int main()
{
    sportsCar s1;

    return 0;
}
