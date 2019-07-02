#include <iostream>
#include <chrono>

struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};

void Function1()
{
    Timer timer;

    for (int i = 0; i < 100; i++)
        std::cout << "Hello" << std::endl;
}

void Function2()
{
    Timer timer;

    for (int i = 0; i < 100; i++)
        std::cout << "Hello\n";
}

int main()
{
    Function1();

    std::cin.get();

    Function2();
}
