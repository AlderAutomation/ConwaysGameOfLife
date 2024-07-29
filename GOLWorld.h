#ifndef GOLWORLD_H
#define GOLWORLD_H

class GOLWorld
{
public: 
    GOLWorld(int wide, int high); 
    int get_width(); 
    int get_height(); 
    void set_width(int wide);
    void set_height(int high); 

private: 
    int width; 
    int height; 

};


#endif