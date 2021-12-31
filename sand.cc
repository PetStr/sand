#include <iostream>
using std::cout;

class co
{
public:
    co() { cout << "co c_tor\n"; }
    ~co() { cout << "co d_tor\n"; }
};

class go
{
public:
    go() { cout << "go c_tor\n"; }
    ~go() { cout << "go d_tor\n"; }
};

int main()
{
    co b;
    try
        {
            go a;
            throw 20;
            cout << "After throw\n";
        }
    catch (int e)
        {
            cout << "An exception occurred. Exception Nr. " << e << '\n';
        }
    cout << "b4 exit\n";
    return 0;
}
