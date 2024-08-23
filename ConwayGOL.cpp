#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<iostream>

#include"GOLWorld.h"

// Prototypes
void drawWorldPopulace(sf::RenderWindow *window, GOLWorld *world, double size, int cellRows, int cellCols); 
void checkNeighbours(GOLWorld *world, int cellRows, int cellCols); 


int main ()
{
    const int WINDOW_WIDTH = 1000; 
    const int WINDOW_HEIGHT = 1000; 
    const int FRAMES = 10; // speed at which life happens 

    const int PIXEL_SIZE = 5; // adjust lower to have more life or higher to have larger life
    // going as low as one is really hard on cpu. I like 5. I debugged at 100. 
    double chanceToLive = 0.60; // adjust higher to have more living 0.00 - 1.00

    int cellRows = WINDOW_HEIGHT/PIXEL_SIZE; 
    int cellCols = WINDOW_WIDTH/PIXEL_SIZE; 

    GOLWorld world(WINDOW_WIDTH, WINDOW_HEIGHT, cellRows, cellCols); 
    
    world.setAliveChance(chanceToLive); 
    world.populateWorld();

    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Conway's Game of Life by Matthew Heltman", sf::Style::Close | sf::Style::Titlebar); 

    drawWorldPopulace(&window, &world, PIXEL_SIZE, cellRows, cellCols);
    checkNeighbours(&world, cellRows, cellCols); 
    window.display();

    window.setFramerateLimit(FRAMES); 


    while (window.isOpen()) {
        sf::Event event; 
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close(); 
                } 
            }
        }

        checkNeighbours(&world, cellRows, cellCols);    
        world.populateNewWorld(); 
        world.swapWorlds();
        drawWorldPopulace(&window, &world, PIXEL_SIZE, cellRows, cellCols);
        window.display();
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


// TODO make this function better. this is a lot of repetiveness and is gross 
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
                            // std::cout << lf.getLivingNeighbours() << std::endl; 
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

            lf.setLivingNeighbours(sumLiveNeighbours); 

            // std::cout << lf.getLivingNeighbours() << std::endl; 

            world->setResident(lf, row, col); 
        }
    }
}