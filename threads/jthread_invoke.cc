// g++-13 -std=c++20 jthread_invoke.cc -o jt -O0 -g -Wall -Werror -Wpedantic

#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

class remote_thread
{
public:
    auto re_thread(int variable) -> int
    {
        variable++;
        value++;
        std::cout << "Starting..." << std::flush;
        std::this_thread::sleep_for(1s);
        std::cout << "Ending." << std::endl;
        return variable;
    }

private:
    int value{0};
};


class next_one
{

public:
    void start_thread(int value)
    {
        trad = std::jthread(
            [&] {
                rte.re_thread(value);
            });
    }

private:
    std::jthread trad;
    remote_thread rte;
};

auto main() -> int
{

    next_one klassen;
    klassen.start_thread(2);


}