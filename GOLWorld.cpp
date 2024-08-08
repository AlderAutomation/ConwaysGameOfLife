#include<vector> 
#include<iostream> 
#include<random> 

#include"GOLWorld.h"
#include"LifeForm.h"


GOLWorld::GOLWorld(int wide, int high, int rows, int cols)
{
    worldWidth = wide; 
    worldHeight = high; 
    worldRows = rows; 
    worldCols = cols;
    currentLifeFormVector.resize(rows, std::vector<LifeForm>(cols));

}

int GOLWorld::getWidth(){
    return worldWidth; 
}

int GOLWorld::getHeight(){
    return worldHeight; 
}

double GOLWorld::getAliveChance(){
    return worldAliveChance; 
}

LifeForm GOLWorld::getResident(int row, int col){
    return currentLifeFormVector[row][col]; 
}

void GOLWorld::setWidth(int wide){
    worldWidth = wide; 
}

void GOLWorld::setHeight(int high){
    worldHeight = high; 
}

void GOLWorld::setRows(int rows){
    worldRows = rows; 
}

void GOLWorld::setCols(int cols){
    worldCols = cols; 
}

void GOLWorld::setAliveChance(double chance){
    worldAliveChance = chance; 
}

void GOLWorld::populateWorld(){
    std::random_device ranDev; 
    std::mt19937 gen(ranDev());
    std::bernoulli_distribution aliveChanceGen(worldAliveChance); 

    for (int row = 0 ; row < worldRows; row ++){
        for (int col = 0 ; col < worldCols ; col ++){
            currentLifeFormVector[row][col].setPosX(row); 
            currentLifeFormVector[row][col].setPosY(col); 
            currentLifeFormVector[row][col].setIsAlive(aliveChanceGen(gen)); 
        }
    }

}

