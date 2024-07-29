#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<iostream>

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

    sf::Window window(sf::VideoMode(800, 600), "Conway"); 

    while (window.isOpen()) {
        sf::Event event; 
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
        }
    }

    return 0;
}