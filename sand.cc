#include <iostream>
#include <vector>
using std::cout;

class A
{
    int num;

public:
    A()
        : num(0)
    {
        cout << "A c_tor: " << num << "\n";
    }
    A(int init)
        : num(init)
    {
        cout << "A c_tor: " << num << "\n";
    }
    ~A() { cout << "A d_tor: " << num << "\n"; }
};

class B
{
    int num;

public:
    B()
        : num(0)
    {
        cout << "B c_tor: " << num << "\n";
    }
    ~B() { cout << "B d_tor: " << num << "\n"; }
};

int main()
{
    A b(10);
    try
        {
            B a;
            std::vector<int> c;
            c.at(20) = 15;
            cout << "Before throw\n";
            throw 20;
            cout << "After throw\n";
        }
    catch (int e)
        {
            cout << "An exception occurred. Exception Nr. " << e << '\n';
        }

    catch (std::exception& e)
        {
            cout << "An exception occurred: " << e.what() << '\n';
        }
    cout << "Before exit\n";
    return 0;
}
