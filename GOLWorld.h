#ifndef GOLWORLD_H
#define GOLWORLD_H

class GOLWorld
{
public: 
    GOLWorld(int wide, int high); 
    int getWidth(); 
    int getHeight(); 
    void setWidth(int wide);
    void setHeight(int high); 

private: 
    int width; 
    int height; 

};


#endif