#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


#include<iostream>

#include"GOLWorld.h"

// Prototypes
void drawLifeForms(sf::RenderWindow *window, double size, double x, double y, bool isAlive); 


int main ()
{
    int windowWidth = 1000; 
    int windowHeight = 1000; 

    int pixelSize = 25; 
    double chanceToLive = 0.75; 

    int cellRows = windowHeight/pixelSize; 
    int cellCols = windowWidth/pixelSize; 

    GOLWorld world(windowWidth, windowHeight, cellRows, cellCols); 
    
    world.setAliveChance(chanceToLive); 
    world.populateWorld(cellRows, cellCols);

    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Conway's Game of Life by Matthew Heltman", sf::Style::Close | sf::Style::Titlebar); 

    for (int row = 0 ; row < cellRows; row ++){
        for (int col = 0 ; col < cellCols ; col ++){
            LifeForm lf = world.getResident(row, col); 
            // std::cout << "resident at: " << lf.getPosX() <<" & " << lf.getPosY() << " is " << lf.getIsAlive() << std::endl; 

            drawLifeForms(&window, pixelSize, lf.getPosX(), lf.getPosY(), lf.getIsAlive()); 
        }
    }


    window.display();


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

void drawLifeForms(sf::RenderWindow *window, double size, double x, double y, bool isAlive){
    sf::RectangleShape lifeformShape(sf::Vector2f(size, size));

    if (isAlive){
        lifeformShape.setFillColor(sf::Color(255, 255, 255));
    } else {
        lifeformShape.setFillColor(sf::Color(0, 0, 0));
    }

    lifeformShape.setPosition(x*size, y*size);

    window->draw(lifeformShape); 

}