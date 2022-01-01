#include "variadic.hh"
#include <iostream>

void doit()
{
    {
        tab a(std::cout, "Hello");
        a.Column(Index {1});
        a.Column(Span {2}, Index {3}, Width{"10.3"});
        a.Column(Index {2}, Width{"10.3"});
        a.Column(Index {2}, Span{3}, Width{"10.3"});
        a.Column(Span {2}, Index {2}, Width{"10.3"}, Hidden{true});               
    }
}


int main()
{
    doit();
    return 0;
}