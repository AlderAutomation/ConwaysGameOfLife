#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


#include<iostream>

#include"GOLWorld.h"

// Prototypes
void drawWorldPopulace(sf::RenderWindow *window, GOLWorld *world, double size, int cellRows, int cellCols); 
void checkNeighbours(GOLWorld *world, int cellRows, int cellCols); 


int main ()
{
    int windowWidth = 1000; 
    int windowHeight = 1000; 

    int pixelSize = 100; 
    double chanceToLive = 0.20; // adjust higher to have more living 0.00 - 1.00

    int cellRows = windowHeight/pixelSize; 
    int cellCols = windowWidth/pixelSize; 

    GOLWorld world(windowWidth, windowHeight, cellRows, cellCols); 
    
    world.setAliveChance(chanceToLive); 
    world.populateWorld(cellRows, cellCols);

    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Conway's Game of Life by Matthew Heltman", sf::Style::Close | sf::Style::Titlebar); 
    std::cout << "Main World: " << &world << std::endl; 

    drawWorldPopulace(&window, &world, pixelSize, cellRows, cellCols);
    checkNeighbours(&world, cellRows, cellCols); 

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
                lifeformShape.setFillColor(sf::Color(0, 0, 0)); // black is alive
            } else {
                lifeformShape.setFillColor(sf::Color(255, 255, 255)); // White is dead 
            }

            lifeformShape.setPosition(lf.getPosX()*size, lf.getPosY()*size);

            window->draw(lifeformShape); 
        }
    }
}

void checkNeighbours(GOLWorld *world, int cellRows, int cellCols){
    LifeForm neighbour; 
    bool isNeighbourAlive = false; 

    std::cout << "checkNeighbours World: " << world << std::endl; 

    // for (int row = 0 ; row < cellRows; row ++){
    //     for (int col = 0 ; col < cellCols ; col ++){

    int row = 1; 
    int col = 1; 

    LifeForm lf = world->getResident(row, col); 
    int sumLiveNeighbours = 0; 

    if ((row >= 1 && col >= 1) && (row < cellRows-1 && col < cellCols-1)) {
        std::cout << "Row: " << row << std::endl; 
        // Top row
        neighbour = world->getResident(row-1, col-1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        neighbour = world->getResident(row-1, col); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        neighbour = world->getResident(row-1, col+1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        // Mid Row 
        neighbour = world->getResident(row, col-1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        neighbour = world->getResident(row, col+1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        // Bottom row
        neighbour = world->getResident(row+1, col-1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        neighbour = world->getResident(row+1, col); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
        neighbour = world->getResident(row+1, col+1); 
        isNeighbourAlive = neighbour.getIsAlive(); 
        std::cout << neighbour.getPosX() << "," << neighbour.getPosY() << " is alive: " << isNeighbourAlive << std::endl; 
        if (isNeighbourAlive == true){
            sumLiveNeighbours++;
        }
            // }

        std::cout << "LifeForm at " << lf.getPosX() << "," << lf.getPosY() << " has " << sumLiveNeighbours << " living neighbours. " << std::endl; 
        }
    // }
}