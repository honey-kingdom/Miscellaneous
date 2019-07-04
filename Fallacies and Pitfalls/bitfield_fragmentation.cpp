#include <iostream>
#include <bitset>

struct MyBitfield
{
    unsigned long b : 3;
    unsigned long   : 13;
};

struct MyBitfield2
{
    unsigned char b1 : 5, b2 : 5, b3 : 5;
};


struct MyBitfield3
{
    unsigned short b1 : 5, b2 : 5, b3 : 5;
};


int
main(void)
{
    MyBitfield aa;

    aa.b = 6;

    std::cout << ++aa.b << std::endl;
    std::cout << ++aa.b << std::endl;

    std::cout << "Size of MyBitfield structure " << sizeof(aa) << std::endl;

    MyBitfield2 bb {};
    MyBitfield3 cc {};

    std::cout << "Size of MyBitfield2 structure " << sizeof(bb) << std::endl; // Fragmentation exists
    std::cout << "Size of MyBitfield3 structure " << sizeof(cc) << std::endl; // No fragmentation

    bb.b1 = 1; // 5 bits (These 5 bits cannot reside along with the next 5 bits within the declared type "unsigned char". So allocate 1 byte in the LSB position solely for these 5 bits.
    bb.b2 = 1; // 5 bits
    bb.b3 = 1; // 5 bits

    auto x = reinterpret_cast<unsigned int &>(bb);

    std::cout << std::bitset<32>(x) << std::endl;
}
