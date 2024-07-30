#ifndef GOLWORLD_H
#define GOLWORLD_H

#include<vector>
#include"LifeForm.h"

class GOLWorld
{
public: 
    GOLWorld(int wide, int high, int rows, int cols); 
    int getWidth(); 
    int getHeight(); 
    LifeForm getResident(int row, int col); 
    void setWidth(int wide);
    void setHeight(int high); 
    void setRows(int rows);
    void setCols(int cols);
    void populateWorld(int rows, int cols); 


private: 
    int width; 
    int height;
    int rows; 
    int cols; 

    std::vector<std::vector<LifeForm>> currentLifeFormVector;

};


#endif