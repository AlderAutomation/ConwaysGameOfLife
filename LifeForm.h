#ifndef LIFEFORM_H
#define LIFEFORM_H

class LifeForm
{
public:
    LifeForm(); // default constructor
    LifeForm(int x, int y, bool alive); // preferred constructor
    ~LifeForm();
    int getPosX(); 
    int getPosY(); 
    bool getIsAlive(); 
    void setPosX(int x); 
    void setPosY(int y); 
    void setIsAlive(bool alive); 


private:
    int posX; 
    int posY; 
    bool isAlive; 
    // Colour: alive = black. dead = white 
};


#endif