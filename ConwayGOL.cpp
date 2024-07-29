#include<iostream>
#include <SFML/Graphics.hpp>

#include"GOLWorld.h"
#include"LifeForm.h"

int main ()
{
    GOLWorld world(100,100); 
    LifeForm being(10, 10, true); 

    std::cout << "World Width: " << world.getWidth() << std::endl; 
    std::cout << "World Height: " << world.getHeight() << std::endl; 

    std::cout << "X: " << being.getPosX() << std::endl; 
    std::cout << "Y: " << being.getPosY() << std::endl; 
    std::cout << "alive: " << being.getIsAlive() << std::endl; 

    std::cout << "hello world" << std::endl; 

    return 0;
}