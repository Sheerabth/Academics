#include <iostream>

int main()
{
    int value = 0;
    int count;
    for(count = 2; count <= 10800/2; count++)
        if(10800 % count == 0)
            value++;
    std::cout << "The answer is " << 2*value << std::endl;
}