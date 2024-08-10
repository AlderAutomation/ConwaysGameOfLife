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
    world.populateWorld();

    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Conway's Game of Life by Matthew Heltman", sf::Style::Close | sf::Style::Titlebar); 

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

            /* sfml appears to be backwards to how I have been programming 
            my X is downwards rows, sfml x is sideways columns
            my Y is sideways cols, sfml y is downwards rows 
            */
            lifeformShape.setPosition(lf.getPosY()*size, lf.getPosX()*size); 

            window->draw(lifeformShape); 
        }
    }
}


void checkNeighbours(GOLWorld *world, int cellRows, int cellCols){
    LifeForm neighbour; 
    bool isNeighbourAlive = false; 

    for (int row = 0 ; row < cellRows; row ++){
        for (int col = 0 ; col < cellCols ; col ++){

            LifeForm lf = world->getResident(row, col); 
            int sumLiveNeighbours = 0; 

            if ((row == 0)) { // first row check.... only has two rows 
                if (col == 0) {
                    // Mid Row 
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else if (col == cellCols-1) {
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else {
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                }
            } else if (row == cellRows-1) {
                if (col == 0) {
                    // top row
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else if (col == cellCols-1) {
                    // top row
                    neighbour = world->getResident(row-1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else {
                    // top row
                    neighbour = world->getResident(row-1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                }
            } else {
                if (col == 0) {
                    // Top row
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else if (col == cellCols-1) {
                    // Top row
                    neighbour = world->getResident(row-1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                } else {
                    // Top row
                    neighbour = world->getResident(row-1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row-1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Mid Row 
                    neighbour = world->getResident(row, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    // Bottom row
                    neighbour = world->getResident(row+1, col-1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                    neighbour = world->getResident(row+1, col+1); 
                    isNeighbourAlive = neighbour.getIsAlive(); 
                    if (isNeighbourAlive == true){
                        sumLiveNeighbours++;
                    }
                }
            }
        
            std::cout << "LifeForm at " << lf.getPosX() << "," << lf.getPosY() << " has " << sumLiveNeighbours << " living neighbours. " << std::endl; 
        }
    }
}