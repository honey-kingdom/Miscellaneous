#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    ~Base() { std::cout << "Base Destructor\n"; } // This function does not know if itself needs to be virtual
};

class Derived: public Base
{
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int
main(void)
{
    Base * aa = new Base();
    delete aa;

    std::cout << "--------------------\n";

    Derived * bb = new Derived();
    delete bb;

    std::cout << "--------------------\n";

    Base * cc = new Derived();
    delete cc;
}
