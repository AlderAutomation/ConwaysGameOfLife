#include<iostream>
//sfml 
#include"GOLWorld.h"

int main ()
{
    GOLWorld world(100,100); 
    std::cout << "World Width: " << world.get_width() << std::endl; 
    std::cout << "World Height: " << world.get_height() << std::endl; 


    return 0;
}