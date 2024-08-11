#ifndef GOLWORLD_H
#define GOLWORLD_H

#include<vector>
#include"LifeForm.h"

class GOLWorld
{
public: 
    // Constructor
    GOLWorld(int wide, int high, int rows, int cols); 
    
    // Getters
    int getWidth(); 
    int getHeight(); 
    double getAliveChance(); 
    LifeForm getResident(int row, int col); 
    
    // Setters
    void setWidth(int wide);
    void setHeight(int high); 
    void setRows(int rows);
    void setCols(int cols);
    void setAliveChance(double chance); 
    void setResident(LifeForm newLifeForm, int row, int col);

    // Special
    void populateWorld(); 
    void populateNewWorld(); 
    void swapWorlds(); 

private: 
    int worldWidth; 
    int worldHeight;
    int worldRows; 
    int worldCols; 
    double worldAliveChance; 

    std::vector<std::vector<LifeForm>> currentLifeFormVector;
    std::vector<std::vector<LifeForm>> newLifeFormVector;
};


#endif