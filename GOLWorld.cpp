#include<vector> 
#include<iostream> 
#include<random> 

#include"GOLWorld.h"
#include"LifeForm.h"


GOLWorld::GOLWorld(int wide, int high, int rows, int cols)
{
    setWidth(wide); 
    setHeight(high); 
    setRows(rows); 
    setCols(cols); 
    currentLifeFormVector.resize(rows, std::vector<LifeForm>(cols));

}

int GOLWorld::getWidth(){
    return width; 
}

int GOLWorld::getHeight(){
    return height; 
}

double GOLWorld::getAliveChance(){
    return aliveChance; 
}

LifeForm GOLWorld::getResident(int row, int col){
    return currentLifeFormVector[row][col]; 
}

void GOLWorld::setWidth(int wide){
    width = wide; 
}

void GOLWorld::setHeight(int high){
    height = high; 
}

void GOLWorld::setRows(int rows){
    rows = rows; 
}

void GOLWorld::setCols(int cols){
    cols = cols; 
}

void GOLWorld::setAliveChance(double chance){
    aliveChance = chance; 
}

void GOLWorld::populateWorld(int rows, int cols){
    std::random_device ranDev; 
    std::mt19937 gen(ranDev());
    std::bernoulli_distribution aliveChanceGen(aliveChance); 

    // TODO fix duplication of row / col variables
    for (int row = 0 ; row < rows; row ++){
        for (int col = 0 ; col < cols ; col ++){
            currentLifeFormVector[row][col].setPosX(row); 
            currentLifeFormVector[row][col].setPosY(col); 
            currentLifeFormVector[row][col].setIsAlive(aliveChanceGen(gen)); 
        }
    }

}

