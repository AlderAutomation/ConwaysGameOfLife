#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


#include<iostream>

#include"GOLWorld.h"

// Prototypes
void drawWorldPopulace(sf::RenderWindow *window, GOLWorld *world, double size, int cellRows, int cellCols); 


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

    drawWorldPopulace(&window, &world, pixelSize, cellRows, cellCols);

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

void drawWorldPopulace(sf::RenderWindow *window, GOLWorld *world, double size, int cellRows, int cellCols){
    for (int row = 0 ; row < cellRows; row ++){
        for (int col = 0 ; col < cellCols ; col ++){
            LifeForm lf = world->getResident(row, col); 

            sf::RectangleShape lifeformShape(sf::Vector2f(size, size));

            if (lf.getIsAlive() ){
                lifeformShape.setFillColor(sf::Color(255, 255, 255));
            } else {
                lifeformShape.setFillColor(sf::Color(0, 0, 0));
            }

            lifeformShape.setPosition(lf.getPosX()*size, lf.getPosY()*size);

            window->draw(lifeformShape); 
        }
    }
}
