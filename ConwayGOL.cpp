#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


#include<iostream>

#include"GOLWorld.h"

int main ()
{
    int windowWidth = 1000; 
    int windowHeight = 1000; 

    int pixelSize = 50; 

    int cellRows = windowHeight/pixelSize; 
    int cellCols = windowWidth/pixelSize; 

    GOLWorld world(windowWidth, windowHeight, cellRows, cellCols); 
    world.populateWorld(cellRows, cellCols);

    for (int row = 0 ; row < cellRows; row ++){
        for (int col = 0 ; col < cellCols ; col ++){
            LifeForm lf = world.getResident(row, col); 
            std::cout << "resident at: " << lf.getPosX() <<" & " << lf.getPosY() << " is " << lf.getIsAlive() << std::endl; 
        }
    }

    sf::Window window(sf::VideoMode(windowHeight, windowWidth), "Conway's Game of Life by Matthew Heltman"); 

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