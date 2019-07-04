#include <iostream>

void
HelloWorld(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
}

int
main()
{
    auto function = HelloWorld;
    function(1);

    void(*cherno)(int) = HelloWorld;
    cherno(2);

    typedef void(*HelloWorldFunction)(int);
    HelloWorldFunction func = HelloWorld;
    func(8);
}
