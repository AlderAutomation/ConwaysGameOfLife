#include "GOLWorld.h"

GOLWorld::GOLWorld(int wide, int high)
{
    setWidth(wide); 
    setHeight(high); 
}

int GOLWorld::getWidth(){
    return width; 
}

int GOLWorld::getHeight(){
    return height; 
}

void GOLWorld::setWidth(int wide){
    width = wide; 
}

void GOLWorld::setHeight(int high){
    height = high; 
}

