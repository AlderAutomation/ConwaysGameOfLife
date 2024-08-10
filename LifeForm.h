#ifndef LIFEFORM_H
#define LIFEFORM_H

class LifeForm
{
public:
    // constructors 
    LifeForm(); // default constructor
    LifeForm(int x, int y, bool alive); // preferred constructor
    
    // destructor
    ~LifeForm();

    // getters 
    int getPosX(); 
    int getPosY(); 
    bool getIsAlive(); 
    bool getIsDying(); 
    int getLivingNeighbours(); 

    // setters
    void setPosX(int x); 
    void setPosY(int y); 
    void setIsAlive(bool alive); 
    void setisDying(bool dying);
    void setLivingNeighbours(int livingNeighbours);
    
private:
    int LF_posX; 
    int LF_posY; 
    bool LF_isAlive; 
    bool LF_isDying;
    int LF_livingNeighbours;
};


#endif