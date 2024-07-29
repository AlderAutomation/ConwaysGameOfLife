#include "GOLWorld.h"

GOLWorld::GOLWorld(int wide, int high)
{
    set_width(wide); 
    set_height(high); 
}

int GOLWorld::get_width(){
    return width; 
}

int GOLWorld::get_height(){
    return height; 
}

void GOLWorld::set_width(int wide){
    width = wide; 
}

void GOLWorld::set_height(int high){
    height = high; 
}

