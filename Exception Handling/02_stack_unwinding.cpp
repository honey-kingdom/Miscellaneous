#include <iostream>

void
f1()
throw (int)
{
    std::cout << "f1() Start" << std::endl;
    throw 100;
    std::cout << "f1() End" << std::endl;
}

void
f2()
throw (int)
{
    std::cout << "f2() Start" << std::endl;
    f1();
    std::cout << "f2() End" << std::endl;
}

void
f3()
{
    std::cout << "f3() Start" << std::endl;
    try
    {
        f2();
    }
    catch (int i)
    {
        std::cout << "Caught Exception: " << i << std::endl;
    }
    std::cout << "f3() End" << std::endl;
}

int
main(void)
{
    f3();

    return 0;
}
