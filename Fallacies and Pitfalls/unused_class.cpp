// Compile with --std=c++14 -Wall -Werror flags
#include <iostream>
#include <chrono>

class Timed {
private:
    std::chrono::high_resolution_clock::time_point start;

public:
    Timed() { start = std::chrono::high_resolution_clock::now(); }
    ~Timed() { std::cout << (std::chrono::high_resolution_clock::now() - start).count() << std::endl; }
};

int
main() {
    Timed tt;
    int x;

    return 0;
}
