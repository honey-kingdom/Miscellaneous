#include <iostream>

class Base {};
class Derived: public Base {};


int
main(void)
{
    Derived d;
    try
    {
        throw d;
    }
    catch(Base b)
    {
        std::cout << "Caught Base Exception" << std::endl;
    }
    catch(Derived d) // This catch block is NEVER executed
    {
        std::cout << "Caught Derived Exception" << std::endl;
    }

    return 0;
}
