#include<vector> 
#include<iostream> 
#include<random> 

#include"GOLWorld.h"
#include"LifeForm.h"

// constructor
GOLWorld::GOLWorld(int wide, int high, int rows, int cols)
{
    worldWidth = wide; 
    worldHeight = high; 
    worldRows = rows; 
    worldCols = cols;
    currentLifeFormVector.resize(rows, std::vector<LifeForm>(cols));
    newLifeFormVector.resize(rows, std::vector<LifeForm>(cols));
}

// getters
int GOLWorld::getWidth() {
    return worldWidth; 
}

int GOLWorld::getHeight() {
    return worldHeight; 
}

double GOLWorld::getAliveChance() {
    return worldAliveChance; 
}

LifeForm GOLWorld::getResident(int row, int col) {
    return currentLifeFormVector[row][col]; 
}

// setters 
void GOLWorld::setWidth(int wide) {
    worldWidth = wide; 
}

void GOLWorld::setHeight(int high) {
    worldHeight = high; 
}

void GOLWorld::setRows(int rows) {
    worldRows = rows; 
}

void GOLWorld::setCols(int cols) {
    worldCols = cols; 
}

void GOLWorld::setAliveChance(double chance) {
    worldAliveChance = chance; 
}

void GOLWorld::setResident(LifeForm newLifeForm, int row, int col) {
    currentLifeFormVector[row][col] = newLifeForm; 
}

// special functions 
void GOLWorld::populateWorld() {
    // function to initial populate the world with randomness 
    std::random_device ranDev; 
    std::mt19937 gen(ranDev());
    std::bernoulli_distribution aliveChanceGen(worldAliveChance); 

    for (int row = 0 ; row < worldRows; row ++) {
        for (int col = 0 ; col < worldCols ; col ++) {
            currentLifeFormVector[row][col].setPosX(row); 
            currentLifeFormVector[row][col].setPosY(col); 
            currentLifeFormVector[row][col].setIsAlive(aliveChanceGen(gen)); 
        }
    }
}

void GOLWorld::populateNewWorld() {
    // function to populate second world and overwrite the first. 
    // first: evaluate each lifeforms amount of neighbour and decide if living or dead. 
        // - Any live cell with fewer than two live neighbours dies (referred to as underpopulation or exposure[2]).  
        // - Any live cell with more than three live neighbours dies (referred to as overpopulation or overcrowding).  
        // - Any live cell with two or three live neighbours lives, unchanged, to the next generation.  
        // - Any dead cell with exactly three live neighbours will come to life. 
    // next: adjust the new world equivalent lifeform information
    // last: overwrite the old world with the new world

    for (int row = 0 ; row < worldRows; row ++) {
        for (int col = 0 ; col < worldCols; col ++) {
            // std::cout << currentLifeFormVector[row][col].getLivingNeighbours() << std::endl; 
            if (currentLifeFormVector[row][col].getIsAlive() == true) {
                if (currentLifeFormVector[row][col].getLivingNeighbours() < 2 ) {
                    newLifeFormVector[row][col] = currentLifeFormVector[row][col]; 
                    newLifeFormVector[row][col].setIsAlive(false); 
                } else if (currentLifeFormVector[row][col].getLivingNeighbours() > 3 ) {
                    newLifeFormVector[row][col] = currentLifeFormVector[row][col]; 
                    newLifeFormVector[row][col].setIsAlive(false); 
                } else if (currentLifeFormVector[row][col].getLivingNeighbours() == 2 || currentLifeFormVector[row][col].getLivingNeighbours() == 3  ) {
                    newLifeFormVector[row][col] = currentLifeFormVector[row][col]; 
                    newLifeFormVector[row][col].setIsAlive(true); 
                } else {
                    std::cout << "Something else?" << std::endl; 
                }
            } else if (currentLifeFormVector[row][col].getIsAlive() == false) {
                if (currentLifeFormVector[row][col].getLivingNeighbours() == 3 ) {
                    newLifeFormVector[row][col] = currentLifeFormVector[row][col]; 
                    newLifeFormVector[row][col].setIsAlive(true); 
                } else {
                    newLifeFormVector[row][col] = currentLifeFormVector[row][col]; 
                }
            }
        }
    }
}

void GOLWorld::swapWorlds() { 
    // felt like this should be done seperately from the populate new world func

    for (int row = 0 ; row < worldRows; row ++) {
        for (int col = 0 ; col < worldCols; col ++) {
            currentLifeFormVector[row][col] = newLifeFormVector[row][col]; 
        }
    }
}