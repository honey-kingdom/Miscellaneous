#include <iostream>

void
fun(int * ptr, int x)
throw(int *, int) // This specifier has been deprecated in C++11 since codes can evolve unmanagable in a large project base.
{
    if (ptr == NULL)
        throw ptr;
    if(x == 0)
        throw x;
    /* Some functionaliry */
}


class Test
{
public:
    Test() { std::cout << "Constructor of Test" << std::endl; }
    ~Test() { std::cout << "Destructor of Test" << std::endl; }
};


class Test2
{
private:
    static int count;
    int id;
public:
    Test2()
    {
        count++;
        id = count;
        std::cout << "Constructing object number " << id << std::endl;
        if (id == 4)
            throw 4;
    }
    ~Test2() { std::cout << "Destructing object number " << id << std::endl; }
};

int Test2::count = 0;


int
main(void)
{
    int x = -1;

    // Simple Example
    std::cout << "Before try" << std::endl;
    try
    {
        std::cout << "Inside try" << std::endl;
        if (x < 0)
        {
            throw x;
            std::cout << "After throw (Never executed)" << std::endl;
        }
    }
    catch (int x)
    {
        std::cout << "Exception Caught" << std::endl;
    }
    std::cout << "After catch (Will be executed)" << std::endl;



    // catch all
    try
    {
        throw 'a';
    }
    catch (int x) // Implicit type conversion does not happen for primitive types.
    {
        std::cout << "Caught " << x;
    }
    catch (...)
    {
        std::cout << "Default Exception" << std::endl;
    }
    // Primitive types : int, char, bool, float, double, void, wchar_t
    


    /*
    try
    {
        throw 'a';
    }
    catch (int x)
    {
        std::cout << "Caught " << std::endl;
    }
    */// If an exception is thrown and not caught anywhere, the program terminates abnormally.



    // nested try-catch blocks
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            std::cout << "Handle Partially" << std::endl;
            throw;
        }
    }
    catch (int x)
    {
        std::cout << "Handle remaining" << std::endl;
    }



    // object lifetime in try block
    try
    {
        Test t1;
        throw 10;
    }
    catch (int i)
    {
        std::cout << "Caught " << i << std::endl;
    }



    // exception handling delegation
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            std::cout << "Inner Catch " << n << std::endl;
            throw; // re-throwing an exception
        }
    }
    catch (int x)
    {
        std::cout << "Outer Catch " << x << std::endl;
    }



    // constructor, destructor calling order
    try
    {
        Test2 array[5];
    }
    catch (int i)
    {
        std::cout << "Caught " << i << std::endl;
    }

    return 0;
}
