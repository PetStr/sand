// This is an example of my interpretation of variadic template implementation.
// It is part of my data to xml spreadsheet implementation.
// Best regards
// Petter Strandh

#include "variadic.hh"
#include <iostream>

void doit()
{
    {
        tab a(std::cout, "Hello");
        // See here the method Column can be called with all possible way of
        // function arguments that is supported. The order does not matter.
        a.Column(Index {1});
        a.Column(Span {2}, Index {3}, Width {"10.3"});
        a.Column(Index {5}, Width {"10.3"});
        a.Column(Index {7}, Span {3}, Width {"10.3"});
        a.Column(Width {"13"});
        a.Column(Span {12}, Index {2}, Width {"10.3"}, Hidden {true});
        a.Column(Hidden {true}, Index {2}, Span {12}, Width {"10.3"});
        a.Column();
    }

    {
        tab a(std::cout, "Hello", false);
        a.Column(Index {1});
        a.Column();
    }

}


int main()
{
    doit();
    return 0;
}