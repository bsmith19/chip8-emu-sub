#include <iostream>
#include "renderer/Display.h"
#include "cpu/Memory.h"

int main(int argc, char** argv)
{
    Memory* mem = new Memory();
    Display* dis = new Display();
    
    std::cout << "Hello World!" << std::endl;

    return 0;
}
